#include "../headers/employeeregistrationwindow.h"
#include "ui_employeeregistrationwindow.h"
#include "../headers/employeemanagerimpl.h"
#include "../headers/employeeimpl.h"
#include <QMessageBox>
#include <QDebug>

EmployeeRegistrationWindow::EmployeeRegistrationWindow(EmployeeImpl* employeeToEdit, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmployeeRegistrationWindow),
    employeeManager()
{
    ui->setupUi(this);
    setupFieldsFromEmployee(employeeToEdit);
    connect(ui->saveButton, &QPushButton::clicked, this, &EmployeeRegistrationWindow::onSaveButtonClicked);
}

void EmployeeRegistrationWindow::setupFieldsFromEmployee(EmployeeImpl* employee) {
    if (employee != nullptr) {
        // Assuming you have similar fields for the Employee in the UI
        ui->editId->setText(QString::fromStdString(employee->getEmployeeId()));
        ui->editName->setText(QString::fromStdString(employee->getFullName()));
        ui->editEmail->setText(QString::fromStdString(employee->getEmail()));
        ui->editCpf->setText(QString::fromStdString(employee->getCPF()));


        ui->labelTitle->setText("Alterar Funcionário");
        ui->saveButton->setText("Salvar Alteração");

        currentEmployee = employee;
    }
}

EmployeeRegistrationWindow::~EmployeeRegistrationWindow()
{
    delete ui;
}

void EmployeeRegistrationWindow::onSaveButtonClicked()
{
    EmployeeImpl employee;
    // Set the employee object with the new values from the UI fields
    employee.setEmployeeId(ui->editId->text().toStdString());
    employee.setFullName(ui->editName->text().toStdString());
    employee.setEmail(ui->editEmail->text().toStdString());
    employee.setCPF(ui->editCpf->text().toStdString());
    employee.setPassword(ui->editPass->text().toStdString());

    std::string confirmPass = ui->editConfirmPass->text().toStdString();

    if(employee.getPassword() == ""){
        QMessageBox::warning(this, "Erro", "Digite uma senha.");
        return;
    }

    if(employee.getPassword() != confirmPass){
        QMessageBox::warning(this, "Erro", "As senhas não coincidem!");
        return;
    }

    bool success;
    if (currentEmployee == nullptr) {
        success = employeeManager.saveEmployee(employee);
    } else {
        success = employeeManager.modifyEmployee(employee);
    }

    if (success) {
        QMessageBox::information(this, "Sucesso", "Sucesso na operação");
    } else {
        QMessageBox::warning(this, "Erro", "Um erro aconteceu!");
    }
}


