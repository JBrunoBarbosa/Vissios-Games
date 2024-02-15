#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QVariantMap>
#include <QVector>

/**
 * @brief A classe DatabaseManager é responsável por gerenciar operações de banco de dados.
 */
class DatabaseManager : public QObject {
    Q_OBJECT

public:
    /**
     * @brief Construtor da classe DatabaseManager.
     * @param databaseName O nome do banco de dados a ser utilizado.
     */
    explicit DatabaseManager(const QString& databaseName);

    /**
     * @brief Destrutor da classe DatabaseManager.
     */
    ~DatabaseManager();

    /**
     * @brief Cria uma tabela no banco de dados.
     * @param tableName O nome da tabela a ser criada.
     * @param schema A estrutura da tabela em SQL.
     * @return true se a tabela foi criada com sucesso, false caso contrário.
     */
    bool createTable(const QString& tableName, const QString& schema);

    /**
     * @brief Executa uma consulta SQL no banco de dados.
     * @param query A consulta SQL a ser executada.
     * @param placeholders Um mapeamento de valores de substituição na consulta.
     * @return true se a consulta foi executada com sucesso, false caso contrário.
     */
    bool executeQuery(const QString& query, const QVariantMap& placeholders = QVariantMap());

    /**
     * @brief Insere um registro em uma tabela.
     * @param tableName O nome da tabela onde o registro será inserido.
     * @param recordData Um mapeamento de dados do registro a ser inserido.
     * @return true se o registro foi inserido com sucesso, false caso contrário.
     */
    bool insertRecord(const QString& tableName, const QVariantMap& recordData);

    /**
     * @brief Seleciona todos os registros de uma tabela.
     * @param tableName O nome da tabela a ser consultada.
     * @return Um vetor de mapeamentos com os registros selecionados.
     */
    QVector<QVariantMap> selectAllRecords(const QString& tableName);

    bool deleteTable(const QString& tableName);

    /**
     * @brief Seleciona registros de uma tabela com base em uma condição.
     * @param tableName O nome da tabela a ser consultada.
     * @param condition A condição de seleção em SQL.
     * @param placeholders Um mapeamento de valores de substituição na condição.
     * @return Um vetor de mapeamentos com os registros selecionados.
     */
    QVector<QVariantMap> selectRecords(const QString& tableName, const QString& condition, const QVariantMap& placeholders = QVariantMap());

private:
    QSqlDatabase db;

    /**
     * @brief Executa uma consulta de seleção SQL no banco de dados.
     * @param query A consulta SQL de seleção a ser executada.
     * @param placeholders Um mapeamento de valores de substituição na consulta.
     * @return Um vetor de mapeamentos com os resultados da consulta.
     */
    QVector<QVariantMap> executeSelectQuery(const QString& query, const QVariantMap& placeholders);
};

#endif // DATABASEMANAGER_H
