#include "testemployee.h"
#include "../../src/headers/employeeimpl.h"

void TestEmployee::initTestCase()
{
}

void TestEmployee::cleanupTestCase()
{
}

void TestEmployee::testSettersAndGetters()
{
    EmployeeImpl employee("1", "John Doe", "johndoe@example.com", "123.456.789-00", "password123");

    // Testa os getters
    QCOMPARE(employee.getEmployeeId(), std::string("1"));
    QCOMPARE(employee.getFullName(), std::string("John Doe"));
    QCOMPARE(employee.getEmail(), std::string("johndoe@example.com"));
    QCOMPARE(employee.getCPF(), std::string("123.456.789-00"));
    QCOMPARE(employee.getPassword(), std::string("password123"));

    // Testa os setters e depois os getters novamente
    employee.setEmployeeId("2");
    employee.setFullName("Jane Doe");
    employee.setEmail("janedoe@example.com");
    employee.setCPF("987.654.321-00");
    employee.setPassword("securePassword");

    QCOMPARE(employee.getEmployeeId(), std::string("2"));
    QCOMPARE(employee.getFullName(), std::string("Jane Doe"));
    QCOMPARE(employee.getEmail(), std::string("janedoe@example.com"));
    QCOMPARE(employee.getCPF(), std::string("987.654.321-00"));
    QCOMPARE(employee.getPassword(), std::string("securePassword"));
}
