#include "gamemanagerimpl.h"
#include "gameimpl.h"
#include "game.h"

GameManagerImpl::GameManagerImpl() : dbManager("vissios_games.sqlite") {
    QString productTableQuery = "id INTEGER PRIMARY KEY, name TEXT, playersQuantity INTEGER, genre TEXT, minAge INTEGER, supplier TEXT";
    dbManager.createTable("Games", productTableQuery);
}

bool GameManagerImpl::saveGame(const Game& game) {
    QVariantMap recordData;
    recordData["id"] = game.getId();
    recordData["name"] = QString::fromStdString(game.getName());
    recordData["playersQuantity"] = game.getPlayerAmount();
    recordData["genre"] = QString::fromStdString(game.getGenre());
    recordData["minAge"] = game.getMinAge();
    recordData["supplier"] = QString::fromStdString(game.getSupplier());
    return dbManager.insertRecord("Games", recordData);
}

bool GameManagerImpl::removeGame(int gameId) {
    QString query = QString("DELETE FROM Games WHERE id = :id");
    QVariantMap placeholders;
    placeholders["id"] = gameId;
    return dbManager.executeQuery(query, placeholders);
}

QVector<GameImpl> GameManagerImpl::listGames() {
    QVector<QVariantMap> records = dbManager.selectAllRecords("Games");
    QVector<GameImpl> games;
    for (const auto& record : records) {
        GameImpl game(record["id"].toInt(),
                      record["name"].toString().toStdString(),
                      record["playersQuantity"].toInt(),
                      record["genre"].toString().toStdString(),
                      record["minAge"].toInt(),
                      record["supplier"].toString().toStdString());
        games.push_back(game);
    }
    return games;
}

bool GameManagerImpl::modifyGame(const Game& game) {
    QString query = QString("UPDATE Games SET name = :name, playersQuantity = :playersQuantity, "
                            "genre = :genre, minAge = :minAge, "
                            "supplier = :supplier WHERE id = :id");
    QVariantMap recordData;
    recordData["name"] = QString::fromStdString(game.getName());
    recordData["playersQuantity"] = game.getPlayerAmount();
    recordData["genre"] = QString::fromStdString(game.getGenre());
    recordData["minAge"] = game.getMinAge();
    recordData["supplier"] = QString::fromStdString(game.getSupplier());
    recordData["id"] = game.getId();
    return dbManager.executeQuery(query, recordData);
}
