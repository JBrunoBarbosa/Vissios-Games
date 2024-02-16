#include "testgame.h"
#include "../../src/headers/gameimpl.h"

void TestGame::initTestCase(){}

void TestGame::cleanupTestCase(){}

void TestGame::testConstructor()
{
    GameImpl game;
    QCOMPARE(game.getId(), 0);
    QCOMPARE(game.getName(), std::string(""));
    QCOMPARE(game.getPlayerAmount(), 0);
    QCOMPARE(game.getGenre(), std::string(""));
    QCOMPARE(game.getMinAge(), 0);
    QCOMPARE(game.getSupplier(), std::string(""));

    GameImpl gameWithData(1, "Test Game", 4, "Strategy", 12, "TestCo");
    QCOMPARE(gameWithData.getId(), 1);
    QCOMPARE(gameWithData.getName(), std::string("Test Game"));
    QCOMPARE(gameWithData.getPlayerAmount(), 4);
    QCOMPARE(gameWithData.getGenre(), std::string("Strategy"));
    QCOMPARE(gameWithData.getMinAge(), 12);
    QCOMPARE(gameWithData.getSupplier(), std::string("TestCo"));
}

void TestGame::testSettersAndGetters()
{
    GameImpl game;
    game.setId(10);
    game.setName("New Game");
    game.setPlayerAmount(2);
    game.setGenre("Adventure");
    game.setMinAge(16);
    game.setSupplier("SupplierCo");

    QCOMPARE(game.getId(), 10);
    QCOMPARE(game.getName(), std::string("New Game"));
    QCOMPARE(game.getPlayerAmount(), 2);
    QCOMPARE(game.getGenre(), std::string("Adventure"));
    QCOMPARE(game.getMinAge(), 16);
    QCOMPARE(game.getSupplier(), std::string("SupplierCo"));
}

