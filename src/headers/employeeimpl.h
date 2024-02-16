#ifndef EMPLOYEEIMPL_H
#define EMPLOYEEIMPL_H

#include "employee.h"

class EmployeeImpl : public Employee
{
private:
    std::string name;
    std::string email;
    std::string cpf;
    std::string id;
    std::string password;

public:
    EmployeeImpl(std::string id = "", std::string name = "", std::string email = "", std::string cpf = "", std::string password = "");
    virtual ~EmployeeImpl();

    // Override setters
    void setFullName(const std::string& name) override;
    void setEmail(const std::string& email) override;
    void setCPF(const std::string& cpf) override;
    void setEmployeeId(const std::string& id) override;
    void setPassword(const std::string& password) override;

    // Override getters
    std::string getFullName() const override;
    std::string getEmail() const override;
    std::string getCPF() const override;
    std::string getEmployeeId() const override;
    std::string getPassword() const override;
};

#endif // EMPLOYEEIMPL_H
