#include <QtTest>
#include "testemployee.h"
#include "testgame.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    int status = 0;

    {
        TestEmployee testEmployee;
        status |= QTest::qExec(&testEmployee, argc, argv);
    }

    {
        TestGame testGame;
        status |= QTest::qExec(&testGame, argc, argv);
    }

    return status;
}
