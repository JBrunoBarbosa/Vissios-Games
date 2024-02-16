#ifndef GAMEMANAGEMENTWINDOW_H
#define GAMEMANAGEMENTWINDOW_H

#include <QWidget>
#include <QTableWidgetItem>
#include "gamemanagerimpl.h"

namespace Ui {
class GameManagementWindow;
}

class GameManagementWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameManagementWindow(QWidget *parent = nullptr);
    ~GameManagementWindow();

signals:
    void openGameRegistrationWindowRequested(GameImpl* game);

private slots:
    void onButtonRemoveGameClicked();
    void onButtonModifyGameClicked();

private:
    Ui::GameManagementWindow *ui;
    GameManagerImpl gameManager;
    GameImpl* createGameFromRow(int row);    // Sua instância do gerenciador de jogos
    void loadGames(); // Método para carregar jogos na tabela
};

#endif // GAMEMANAGEMENTWINDOW_H
