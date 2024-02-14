#include "gameregistrationwindow.h"
#include "ui_gameregistrationwindow.h"

GameRegistrationWindow::GameRegistrationWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameRegistrationWindow)
{
    ui->setupUi(this);
}

GameRegistrationWindow::~GameRegistrationWindow()
{
    delete ui;
}
