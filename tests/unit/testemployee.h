#ifndef TESTEMPLOYEEIMPL_H
#define TESTEMPLOYEEIMPL_H

#include <QtTest>

class TestEmployee : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase(); // Chamado antes dos primeiros testes
    void cleanupTestCase(); // Chamado após o último teste
    void testSettersAndGetters(); // Testa os setters e getters
};

#endif
