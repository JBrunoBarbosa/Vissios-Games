#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include "employee.h"
#include "employeeimpl.h"
#include <QVector>

/**
 * @brief Interface abstrata para gerenciamento de operações relacionadas a funcionários.
 *
 * Define um contrato para as operações CRUD que devem ser implementadas para gerenciar funcionários.
 */
class EmployeeManager {
public:
    virtual ~EmployeeManager() {}

    /**
     * @brief Salva um funcionário no banco de dados.
     *
     * @param employee Referência constante para o funcionário a ser salvo.
     * @return true se o funcionário for salvo com sucesso, false caso contrário.
     */
    virtual bool saveEmployee(const Employee& employee) = 0;

    /**
     * @brief Remove um funcionário do banco de dados pelo seu ID.
     *
     * @param employeeId ID do funcionário a ser removido.
     * @return true se o funcionário for removido com sucesso, false caso contrário.
     */
    virtual bool removeEmployee(const std::string& employeeId) = 0;

    /**
     * @brief Lista todos os funcionários do banco de dados.
     *
     * @return QVector<EmployeeImpl> contendo todos os funcionários.
     */
    virtual QVector<EmployeeImpl> listEmployees() = 0;

    /**
     * @brief Modifica os dados de um funcionário existente no banco de dados.
     *
     * @param employee Referência constante para o funcionário com os dados atualizados.
     * @return true se o funcionário for modificado com sucesso, false caso contrário.
     */
    virtual bool modifyEmployee(const Employee& employee) = 0;
};

#endif // EMPLOYEEMANAGER_H
