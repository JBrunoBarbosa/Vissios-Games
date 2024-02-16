#include "../headers/mainwindow.h"
#include "../headers/gameregistrationwindow.h"
#include "../headers/gamemanagementwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentWidget(nullptr)
{
    ui->setupUi(this);
    connect(ui->navigateToGames, &QAction::triggered, this, [this]() { openWidget(new GameRegistrationWindow(nullptr, this)); });
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

void MainWindow::openGameRegistrationWindow(GameImpl* game) {
    openWidget(new GameRegistrationWindow(game, this));
}
