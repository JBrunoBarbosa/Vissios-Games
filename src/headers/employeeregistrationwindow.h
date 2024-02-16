#ifndef EMPLOYEEREGISTRATIONWINDOW_H
#define EMPLOYEEREGISTRATIONWINDOW_H

#include <QWidget>
#include "employeeimpl.h"
#include "employeemanagerimpl.h"

namespace Ui {
class EmployeeRegistrationWindow;
}

class EmployeeRegistrationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeeRegistrationWindow(EmployeeImpl* employeeToEdit, QWidget *parent = nullptr);
    ~EmployeeRegistrationWindow();

private slots:
    void onSaveButtonClicked();

private:
    Ui::EmployeeRegistrationWindow *ui;
    EmployeeImpl* currentEmployee = nullptr;
    EmployeeManagerImpl employeeManager;
    void setupFieldsFromEmployee(EmployeeImpl* employee);
};

#endif // EMPLOYEEREGISTRATIONWINDOW_H
