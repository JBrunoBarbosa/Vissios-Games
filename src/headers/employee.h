#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

/**
 * @brief Abstract class for Employee representation.
 *
 * This class provides the interface for employee operations. It includes
 * pure virtual functions for setting and getting employee attributes.
 */
class Employee
{
public:
    virtual ~Employee() {}

    // Setters
    /**
     * @brief Set the Full Name of the employee.
     * @param name Full name of the employee.
     */
    virtual void setFullName(const std::string& name) = 0;

    /**
     * @brief Set the Email of the employee.
     * @param email Email address of the employee.
     */
    virtual void setEmail(const std::string& email) = 0;

    /**
     * @brief Set the CPF of the employee.
     * @param cpf CPF number of the employee (Brazilian tax ID).
     */
    virtual void setCPF(const std::string& cpf) = 0;

    /**
     * @brief Set the Employee ID.
     * @param id Unique identifier for the employee.
     */
    virtual void setEmployeeId(const std::string& id) = 0;

    /**
     * @brief Set the Password of the employee.
     * @param password Password for the employee account.
     */
    virtual void setPassword(const std::string& password) = 0;

    // Getters
    /**
     * @brief Get the Full Name of the employee.
     * @return Full name as a string.
     */
    virtual std::string getFullName() const = 0;

    /**
     * @brief Get the Email of the employee.
     * @return Email as a string.
     */
    virtual std::string getEmail() const = 0;

    /**
     * @brief Get the CPF of the employee.
     * @return CPF as a string.
     */
    virtual std::string getCPF() const = 0;

    /**
     * @brief Get the Employee ID.
     * @return Employee ID as a string.
     */
    virtual std::string getEmployeeId() const = 0;

    /**
     * @brief Get the Password of the employee.
     * @return Password as a string.
     */
    virtual std::string getPassword() const = 0;
};

#endif // EMPLOYEE_H
