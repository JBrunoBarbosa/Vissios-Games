#include "gameregistrationwindow.h"
#include "ui_gameregistrationwindow.h"
#include "gamemanagerimpl.h"
#include "gameimpl.h"
#include <QDebug>

GameRegistrationWindow::GameRegistrationWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameRegistrationWindow)
{
    ui->setupUi(this);
    connect(ui->saveButton, &QPushButton::clicked, this, &GameRegistrationWindow::onSaveButtonClicked);
}

GameRegistrationWindow::~GameRegistrationWindow()
{
    delete ui;
}

void GameRegistrationWindow::onSaveButtonClicked()
{
    // Supondo que você tenha esses widgets na sua UI. Ajuste os nomes conforme necessário.
    int id = ui->editIdGame->text().toInt();
    std::string name = ui->editName->text().toStdString();
    int playersNumber = ui->editPlayersQuantity->text().toInt();
    std::string genre = ui->editTheme->text().toStdString();
    int minAge = ui->editAge->text().toInt();
    std::string supplier = ui->editSupplier->text().toStdString();

    // Criação da instância GameImpl com os dados coletados.
    GameImpl game(id, name, playersNumber, genre, minAge, supplier); // Supondo que ID seja gerado automaticamente ou não necessário aqui.

    // Usando o GameManager para salvar o jogo.
    GameManagerImpl gameManager;
    if(gameManager.saveGame(game)) {
        qDebug() << "O jogo foi salvo com sucesso.";
    } else {
        qDebug() << "Falha ao salvar o jogo.";
    }
}
