#ifndef TESTGAME_H
#define TESTGAME_H

#include <QtTest>

class TestGame : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void testConstructor();
    void testSettersAndGetters();
    void cleanupTestCase();
};

#endif
