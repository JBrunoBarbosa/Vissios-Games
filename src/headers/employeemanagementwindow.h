#ifndef EMPLOYEEMANAGEMENTWINDOW_H
#define EMPLOYEEMANAGEMENTWINDOW_H

#include <QWidget>
#include <QTableWidgetItem>
#include "employeemanagerimpl.h"

namespace Ui {
class EmployeeManagementWindow;
}

class EmployeeManagementWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeeManagementWindow(QWidget *parent = nullptr);
    ~EmployeeManagementWindow();

signals:
    void openEmployeeRegistrationWindowRequested(EmployeeImpl* employee);

private slots:
    void onButtonRemoveEmployeeClicked();
    void onButtonModifyEmployeeClicked();

private:
    Ui::EmployeeManagementWindow *ui;
    EmployeeManagerImpl employeeManager;
    EmployeeImpl* createEmployeeFromRow(int row);
    void loadEmployees();
};

#endif
