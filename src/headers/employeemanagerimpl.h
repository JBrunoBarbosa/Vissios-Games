#ifndef EMPLOYEEMANAGERIMPL_H
#define EMPLOYEEMANAGERIMPL_H

#include "employeemanager.h"
#include "databasemanager.h" // Assuming you have a similar class for database operations

class EmployeeManagerImpl : public EmployeeManager {
private:
    DatabaseManager dbManager;

public:
    EmployeeManagerImpl();
    bool saveEmployee(const Employee& employee) override;
    bool removeEmployee(const std::string& employeeId) override;
    QVector<EmployeeImpl> listEmployees() override;
    bool modifyEmployee(const Employee& employee) override;
};

#endif // EMPLOYEEMANAGERIMPL_H
