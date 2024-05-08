#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "elevator.h"
#include "outerbutton.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Elevator* elevator[5];
    outerbutton* outerbtn;
    std::queue<int>outerTaskList;
private:
    void init_elevator();
    void init_outerbtn();
private slots:
    void onClicked(int dstfloor);
    void receivedIdle();
};
#endif // MAINWINDOW_H
