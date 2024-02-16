#include "../headers/employeemanagerimpl.h"
#include "../headers/employeeimpl.h"
#include "../headers/employee.h"

EmployeeManagerImpl::EmployeeManagerImpl() : dbManager("vissios_employees.sqlite") {
    QString employeeTableQuery = "id TEXT PRIMARY KEY, name TEXT, email TEXT, cpf TEXT, password TEXT";
    dbManager.createTable("Employees", employeeTableQuery);
}

bool EmployeeManagerImpl::saveEmployee(const Employee& employee) {
    QVariantMap recordData;
    recordData["id"] = QString::fromStdString(employee.getEmployeeId());
    recordData["name"] = QString::fromStdString(employee.getFullName());
    recordData["email"] = QString::fromStdString(employee.getEmail());
    recordData["cpf"] = QString::fromStdString(employee.getCPF());
    recordData["password"] = QString::fromStdString(employee.getPassword());
    return dbManager.insertRecord("Employees", recordData);
}

bool EmployeeManagerImpl::removeEmployee(const std::string& employeeId) {
    QString query = QString("DELETE FROM Employees WHERE id = :id");
    QVariantMap placeholders;
    placeholders["id"] = QString::fromStdString(employeeId);
    return dbManager.executeQuery(query, placeholders);
}

QVector<EmployeeImpl> EmployeeManagerImpl::listEmployees() {
    QVector<QVariantMap> records = dbManager.selectAllRecords("Employees");
    QVector<EmployeeImpl> employees;
    for (const auto& record : records) {
        EmployeeImpl employee;
        employee.setEmployeeId(record["id"].toString().toStdString());
        employee.setFullName(record["name"].toString().toStdString());
        employee.setEmail(record["email"].toString().toStdString());
        employee.setCPF(record["cpf"].toString().toStdString());
        employee.setPassword(record["password"].toString().toStdString());
        employees.push_back(employee);
    }
    return employees;
}

bool EmployeeManagerImpl::modifyEmployee(const Employee& employee) {
    QString query = QString("UPDATE Employees SET name = :name, email = :email, cpf = :cpf, "
                            "password = :password WHERE id = :id");
    QVariantMap recordData;
    recordData["name"] = QString::fromStdString(employee.getFullName());
    recordData["email"] = QString::fromStdString(employee.getEmail());
    recordData["cpf"] = QString::fromStdString(employee.getCPF());
    recordData["password"] = QString::fromStdString(employee.getPassword());
    recordData["id"] = QString::fromStdString(employee.getEmployeeId());
    return dbManager.executeQuery(query, recordData);
}
