#include "../headers/gamemanagementwindow.h"
#include "../headers/mainwindow.h"
#include "ui_gamemanagementwindow.h"
#include <QMessageBox>

GameManagementWindow::GameManagementWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameManagementWindow),
    gameManager()
{
    ui->setupUi(this);
    connect(ui->buttonRemoveGame, &QPushButton::clicked, this, &GameManagementWindow::onButtonRemoveGameClicked);
    connect(ui->buttonModifyGame, &QPushButton::clicked, this, &GameManagementWindow::onButtonModifyGameClicked);

    loadGames(); // Carregar jogos na tabela ao iniciar
}

GameManagementWindow::~GameManagementWindow()
{
    delete ui;
}

void GameManagementWindow::loadGames()
{
    // Exemplo de como carregar e exibir jogos na QTableWidget
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    QVector<GameImpl> games = gameManager.listGames();
    for (int i = 0; i < games.size(); ++i) {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(games[i].getId())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(games[i].getName())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(games[i].getMinAge())));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(games[i].getGenre())));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(games[i].getPlayerAmount())));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(games[i].getSupplier())));
    }

    ui->tableWidget->resizeColumnsToContents();
}

void GameManagementWindow::onButtonModifyGameClicked()
{
    int row = ui->tableWidget->currentRow();
    if (row != -1) {
        GameImpl* gameToEdit = createGameFromRow(row);
        MainWindow* mainWindow = qobject_cast<MainWindow*>(parentWidget());
        mainWindow->openGameRegistrationWindow(gameToEdit);
    } else {
        QMessageBox::warning(this, "Seleção", "Por favor, selecione um jogo para alterar.");
    }
}

GameImpl* GameManagementWindow::createGameFromRow(int row) {
    int id = ui->tableWidget->item(row, 0)->text().toInt();
    std::string name = ui->tableWidget->item(row, 1)->text().toStdString();
    int minAge = ui->tableWidget->item(row, 2)->text().toInt();
    std::string genre = ui->tableWidget->item(row, 3)->text().toStdString();
    int playerAmount = ui->tableWidget->item(row, 4)->text().toInt();
    std::string supplier = ui->tableWidget->item(row, 5)->text().toStdString();

    return new GameImpl(id, name, playerAmount, genre, minAge, supplier);
}

void GameManagementWindow::onButtonRemoveGameClicked()
{
    // Exemplo de remoção de um jogo selecionado
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow >= 0) {
        int gameId = ui->tableWidget->item(currentRow, 0)->text().toInt();
        if (gameManager.removeGame(gameId)) {
            QMessageBox::information(this, "Sucesso", "Jogo removido com sucesso.");
            loadGames();
        } else {
            QMessageBox::warning(this, "Erro", "Não foi possível remover o jogo.");
        }
    } else {
        QMessageBox::warning(this, "Seleção", "Por favor, selecione um jogo para remover.");
    }
}
