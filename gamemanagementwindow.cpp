#include "GameManagementWindow.h"
#include "ui_GameManagementWindow.h"
#include <QMessageBox>

GameManagementWindow::GameManagementWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameManagementWindow),
    gameManager()
{
    ui->setupUi(this);
    // Conecte botões (assumindo que você tenha botões nomeados adequadamente na sua UI) aos slots
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

void GameManagementWindow::onButtonModifyGameClicked()
{
    // Aqui, você precisaria abrir um diálogo ou forma similar para coletar as novas informações
    // do jogo que deseja modificar, e então chamar gameManager.modifyGame(updatedGame);
    // Este exemplo não inclui a implementação desse diálogo.
}
