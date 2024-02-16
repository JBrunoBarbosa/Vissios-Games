#include "../headers/mainwindow.h"
#include "../headers/gameregistrationwindow.h"
#include "../headers/gamemanagementwindow.h"
#include "../headers/employeeregistrationwindow.h"
#include "../headers/employeemanagementwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentWidget(nullptr)
{
    ui->setupUi(this);
    connect(ui->navigateToGames, &QAction::triggered, this, [this]() { openWidget(new GameRegistrationWindow(nullptr, this)); });
    connect(ui->navigateToManageGames, &QAction::triggered, this, [this]() { openWidget(new GameManagementWindow(this)); });
    connect(ui->navigateToEmployee, &QAction::triggered, this, [this]() { openWidget(new EmployeeRegistrationWindow(nullptr, this)); });
    connect(ui->navigateToManageEmployee, &QAction::triggered, this, [this]() { openWidget(new EmployeeManagementWindow(this)); });
}

MainWindow::~MainWindow() {
    delete ui;
    delete currentWidget;
}

void MainWindow::openWidget(QWidget* widget) {
    if (widget) {
        delete currentWidget;
        currentWidget = widget;
        setCentralWidget(currentWidget);
    }
}

void MainWindow::openGameRegistrationWindow(GameImpl* game) {
    openWidget(new GameRegistrationWindow(game, this));
}

void MainWindow::openEmployeeRegistrationWindow(EmployeeImpl* employee) {
    openWidget(new EmployeeRegistrationWindow(employee, this));
}
