#include "mainwindow.h"
#include "gameregistrationwindow.h"
#include "gamemanagementwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentWidget(nullptr) {
    ui->setupUi(this);
    connect(ui->navigateToGames, &QAction::triggered, this, [this]() { openWidget(new GameRegistrationWindow(this)); });
    connect(ui->navigateToManageGames, &QAction::triggered, this, [this]() { openWidget(new GameManagementWindow(this)); });

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
