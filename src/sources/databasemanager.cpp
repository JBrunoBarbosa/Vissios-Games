#include "../headers/databasemanager.h"
#include <QDebug>
#include <QSqlError>
#include <QDir>
#include <QStandardPaths>
#include <QSqlQuery>
#include <QSqlRecord>

DatabaseManager::DatabaseManager(const QString& databaseName) {
    QString dbPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(dbPath);
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    dbPath += QDir::separator();
    dbPath += databaseName;  // Adiciona o nome do arquivo do banco de dados ao caminho

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);

    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
    } else {
        qDebug() << "Database opened successfully at:" << dbPath;
    }
}

DatabaseManager::~DatabaseManager() {
    db.close();
}

bool DatabaseManager::createTable(const QString& tableName, const QString& schema) {
    QString query = "CREATE TABLE IF NOT EXISTS " + tableName + " (" + schema + ")";
    return executeQuery(query);
}

bool DatabaseManager::executeQuery(const QString& query, const QVariantMap& placeholders) {
    db.transaction();
    QSqlQuery sqlQuery;

    sqlQuery.prepare(query);

    for (const auto& key : placeholders.keys()) {
        sqlQuery.bindValue(":" + key, placeholders.value(key));
    }

    if (!sqlQuery.exec()) {
        qDebug() << "Execute query error:" << sqlQuery.lastError().text();
        db.rollback();


        qDebug() << "Query: " << query;
        qDebug() << "Placeholders: " << placeholders;
        qDebug() << "Insert record error:" << sqlQuery.lastError().text();
        return false;
    }

    db.commit();
    return true;

}

bool DatabaseManager::insertRecord(const QString& tableName, const QVariantMap& recordData) {

    QString fields;
    QString placeholders;

    for (const auto& key : recordData.keys()) {
        fields += key + ",";
        placeholders += ":" + key + ",";
    }

    qDebug() << "Query: " << fields;
    qDebug() << "Placeholders: " << placeholders;

    fields.chop(1);
    placeholders.chop(1);

    QString query = "INSERT OR IGNORE INTO " + tableName + " (" + fields + ") VALUES (" + placeholders + ")";
    return executeQuery(query, recordData);
}

QVector<QVariantMap> DatabaseManager::selectRecords(const QString& tableName, const QString& condition, const QVariantMap& placeholders) {
    QString query = "SELECT * FROM " + tableName + " WHERE " + condition;
    return executeSelectQuery(query, placeholders);
}

QVector<QVariantMap> DatabaseManager::selectAllRecords(const QString& tableName) {
    QString query = "SELECT * FROM " + tableName;
    return executeSelectQuery(query, QVariantMap());
}

QVector<QVariantMap> DatabaseManager::executeSelectQuery(const QString& query, const QVariantMap& placeholders) {
    QSqlQuery sqlQuery;
    sqlQuery.prepare(query);

    for (const auto& key : placeholders.keys()) {
        sqlQuery.bindValue(":" + key, placeholders.value(key));
    }

    if (!sqlQuery.exec()) {
        qDebug() << "Execute query error:" << sqlQuery.lastError().text();
        return QVector<QVariantMap>();
    }

    QVector<QVariantMap> results;
    QSqlRecord record = sqlQuery.record();

    while (sqlQuery.next()) {
        QVariantMap row;
        for (int i = 0; i < record.count(); i++) {
            row[record.fieldName(i)] = sqlQuery.value(i);
        }
        results.push_back(row);
    }

    return results;
}

bool DatabaseManager::deleteTable(const QString& tableName) {
    QString query = QString("DROP TABLE IF EXISTS %1").arg(tableName);
    QSqlQuery sqlQuery;

    if (!sqlQuery.exec(query)) {
        qDebug() << "Erro ao deletar tabela:" << sqlQuery.lastError().text();
        return false;
    }

    return true;
}
