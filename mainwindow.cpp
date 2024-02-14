#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameregistrationwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentWidget(nullptr) {
    ui->setupUi(this);
    connect(ui->navigateToUsers, &QAction::triggered, this, [this]() { openWidget(new GameRegistrationWindow(this)); });
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
