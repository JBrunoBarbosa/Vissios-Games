#ifndef GAMEMANAGERIMPL_H
#define GAMEMANAGERIMPL_H

#include "game.h"
#include "gamemanager.h"
#include "databasemanager.h"
#include <QVector>

class GameManagerImpl : public GameManager
{
public:
    GameManagerImpl();
    bool saveGame(const Game& game) override;
    bool removeGame(int gameId) override;
    QVector<GameImpl> listGames() override;
    bool modifyGame(const Game& game) override;

private:
    DatabaseManager dbManager;
};

#endif
