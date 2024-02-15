#include "gameregistrationwindow.h"
#include "ui_gameregistrationwindow.h"
#include "gamemanagerimpl.h"
#include "gameimpl.h"
#include <QMessageBox>
#include <QDebug>

GameRegistrationWindow::GameRegistrationWindow(GameImpl* gameToEdit, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameRegistrationWindow),
    gameManager()
{
    ui->setupUi(this);
    setupFieldsFromGame(gameToEdit);
    connect(ui->saveButton, &QPushButton::clicked, this, &GameRegistrationWindow::onSaveButtonClicked);
}

void GameRegistrationWindow::setupFieldsFromGame(GameImpl* game) {
    if (game != nullptr) {
        ui->editIdGame->setText(QString::number(game->getId()));
        ui->editName->setText(QString::fromStdString(game->getName()));
        ui->editPlayersQuantity->setText(QString::number(game->getPlayerAmount()));
        ui->editTheme->setText(QString::fromStdString(game->getGenre()));
        ui->editAge->setText(QString::number(game->getMinAge()));
        ui->editSupplier->setText(QString::fromStdString(game->getSupplier()));
        ui->labelTitle->setText("Alterar Jogo");
        ui->saveButton->setText("Salvar Alteração");

        currentGame = game;
    }

}

GameRegistrationWindow::~GameRegistrationWindow()
{
    delete ui;
}

void GameRegistrationWindow::onSaveButtonClicked()
{
    GameImpl game; // Crie o objeto de jogo com os novos valores
    game.setId(ui->editIdGame->text().toInt()); // Observe que para atualização, o ID deve ser preservado
    game.setName(ui->editName->text().toStdString());
    game.setPlayerAmount(ui->editPlayersQuantity->text().toInt());
    game.setGenre(ui->editTheme->text().toStdString());
    game.setMinAge(ui->editAge->text().toInt());
    game.setSupplier(ui->editSupplier->text().toStdString());

    bool success;
    if (currentGame == nullptr) {
        success = gameManager.saveGame(game);
    } else {
        success = gameManager.modifyGame(game);
    }

    if (success) {
        QMessageBox::information(this, "Sucesso", "Operaçao feita com sucesso.");
    } else {
        QMessageBox::warning(this, "Erro", "Algum erro ocorreu.");
    }
}
