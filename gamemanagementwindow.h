#ifndef GAMEMANAGEMENTWINDOW_H
#define GAMEMANAGEMENTWINDOW_H

#include <QWidget>
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

private slots:
    void onButtonRemoveGameClicked();
    void onButtonModifyGameClicked();
    // Você pode adicionar slots para carregar jogos, etc.

private:
    Ui::GameManagementWindow *ui;
    GameManagerImpl gameManager; // Assumindo que você tem uma instância de GameManager
    void loadGames(); // Método para carregar jogos na tabela
};

#endif // GAMEMANAGEMENTWINDOW_H
