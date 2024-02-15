#ifndef GAMEREGISTRATIONWINDOW_H
#define GAMEREGISTRATIONWINDOW_H

#include <QWidget>

namespace Ui {
class GameRegistrationWindow;
}

class GameRegistrationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameRegistrationWindow(QWidget *parent = nullptr);
    ~GameRegistrationWindow();

private slots:
    void onSaveButtonClicked();

private:
    Ui::GameRegistrationWindow *ui;
};

#endif
