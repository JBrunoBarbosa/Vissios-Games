#include "../headers/employeeimpl.h"

EmployeeImpl::EmployeeImpl(std::string id, std::string name, std::string email, std::string cpf, std::string password)
    : name(name), email(email),  cpf(cpf), id(id), password(password)
{
}
EmployeeImpl::~EmployeeImpl() {}

void EmployeeImpl::setFullName(const std::string& newName) {
    name = newName;
}

void EmployeeImpl::setEmail(const std::string& email) {
    this->email = email;
}

void EmployeeImpl::setCPF(const std::string& cpf) {
    this->cpf = cpf;
}

void EmployeeImpl::setEmployeeId(const std::string& id) {
    this->id = id;
}

void EmployeeImpl::setPassword(const std::string& password) {
    this->password = password;
}

std::string EmployeeImpl::getFullName() const {
    return name;
}

std::string EmployeeImpl::getEmail() const {
    return email;
}

std::string EmployeeImpl::getCPF() const {
    return cpf;
}

std::string EmployeeImpl::getEmployeeId() const {
    return id;
}

std::string EmployeeImpl::getPassword() const {
    return password;
}
