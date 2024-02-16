#include "../headers/employeemanagementwindow.h"
#include "../headers/mainwindow.h"
#include "ui_employeemanagementwindow.h"
#include <QMessageBox>

EmployeeManagementWindow::EmployeeManagementWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmployeeManagementWindow),
    employeeManager()
{
    ui->setupUi(this);
    connect(ui->buttonRemoveEmployee, &QPushButton::clicked, this, &EmployeeManagementWindow::onButtonRemoveEmployeeClicked);
    connect(ui->buttonModifyEmployee, &QPushButton::clicked, this, &EmployeeManagementWindow::onButtonModifyEmployeeClicked);

    loadEmployees();
}

EmployeeManagementWindow::~EmployeeManagementWindow()
{
    delete ui;
}

void EmployeeManagementWindow::loadEmployees()
{
    // Example of how to load and display employees in the QTableWidget
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    QVector<EmployeeImpl> employees = employeeManager.listEmployees();
    for (int i = 0; i < employees.size(); ++i) {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(employees[i].getEmployeeId())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(employees[i].getFullName())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(employees[i].getEmail())));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(employees[i].getCPF())));

    }

    ui->tableWidget->resizeColumnsToContents();
}

void EmployeeManagementWindow::onButtonModifyEmployeeClicked()
{
    int row = ui->tableWidget->currentRow();
    if (row != -1) {
        EmployeeImpl* employeeToEdit = createEmployeeFromRow(row);
        MainWindow* mainWindow = qobject_cast<MainWindow*>(parentWidget());
        mainWindow->openEmployeeRegistrationWindow(employeeToEdit);
    } else {
        QMessageBox::warning(this, "Selection", "Por favor selecione um funcionário para editar.");
    }
}

EmployeeImpl* EmployeeManagementWindow::createEmployeeFromRow(int row) {
    std::string id = ui->tableWidget->item(row, 0)->text().toStdString();
    std::string name = ui->tableWidget->item(row, 1)->text().toStdString();
    std::string email = ui->tableWidget->item(row, 2)->text().toStdString();
    std::string cpf = ui->tableWidget->item(row, 3)->text().toStdString();

    return new EmployeeImpl(id, name, email, cpf, "");
}

void EmployeeManagementWindow::onButtonRemoveEmployeeClicked()
{
    // Example of removing a selected employee
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow >= 0) {
        std::string employeeId = ui->tableWidget->item(currentRow, 0)->text().toStdString();
        if (employeeManager.removeEmployee(employeeId)) {
            QMessageBox::information(this, "Sucesso", "Funcionário removido com sucesso!");
            loadEmployees();
        } else {
            QMessageBox::warning(this, "Erro", "Um erro ocorreu!");
        }
    } else {
        QMessageBox::warning(this, "Seleção", "Por favor selecione um funcionário para remover !");
    }
}
