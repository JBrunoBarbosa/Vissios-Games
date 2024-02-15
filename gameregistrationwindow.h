#ifndef GAMEREGISTRATIONWINDOW_H
#define GAMEREGISTRATIONWINDOW_H

#include <QWidget>
#include "gameimpl.h"
#include "gamemanagerimpl.h"

namespace Ui {
class GameRegistrationWindow;
}

class GameRegistrationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameRegistrationWindow(GameImpl* gameToEdit, QWidget *parent);
    ~GameRegistrationWindow();

private slots:
    void onSaveButtonClicked();

private:
    Ui::GameRegistrationWindow *ui;
    GameImpl* currentGame = nullptr;
    GameManagerImpl gameManager;
    void setupFieldsFromGame(GameImpl* game);
};

#endif
