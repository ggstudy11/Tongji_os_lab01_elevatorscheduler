#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QLCDNumber>
#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <queue>
#include <QTime>
#include <QEventLoop>
#include <QCoreApplication>
#include "emergency.h"

/*
 *elevator has for 4 val status
 *
 *status = 0 represent elevator is idle
 *status = 1 represent elevator is moving for inner task
 *status = 2 represent elevator is waiting for innter task
 *status = 3 represent elevator is moving for outer task
 *status = 4 represent elevator has sth wrong
 *
 *different from most 3 val status from others
 *eg. status = 1 for up status = 2 for down status = 3 for idle
*/







const int maxFloor = 20;
const int startFloor = 20;

class Elevator : public QWidget
{
    Q_OBJECT
public:
    explicit Elevator(QWidget *parent = nullptr);
    bool isRunning();
    // if status == 1 or not
    void addTask(int dstFloor);
    // for elevatorscheduler
    bool isfree();
    // if status == 0 or not
    int currentPosition();
    // return currentFloor
private slots:
    void moveTo();
    // move
    void emStop();
    // stop when emergency happened
    void update_position_label(int value);
    // update position label
    void update_doorstatus_label(int door_status);
    // update door open or close status
    void update_status_label(int status);
    // update elevator status
    void btn_openDoor();
    // btn slot for door open
    void btn_closeDoor();
    // btn slot for door close
private:
    QPushButton     *innerbtn[20]; // btn for dstfloor
    QSlider         *elevator; // slider to stimulate elevator
    QLabel          *positionlabel; // show the position now
    QLabel          *doorlabel; // show the door status
    int             currentFloor; //
    int             status;// elevator status
    std::queue<int> taskList; // running tasks FIFO queue to cope with the dst required first
    int             door_status; //
    QPushButton     *embtn; // btn for emergency
    QLabel          *elevator_status; // show status
    QPushButton     *btn_open_door; // btn for door open
    QPushButton     *btn_close_door; // btn for door close
    QLCDNumber      *plabel;
private:
    void init_elevator();
    // init slider position , sheetstyle ,size ,signal or someting
    void init_btn_door();
    // init btn for door open or close
    void init_positionlabel();
    // init label for currentfloor
    void init_doorlabel();
    // init label for door status
    void init_embtn();
    // init btn for emergency
    void init_innerbtn();
    // init btn for dstfloor
    void init_elevator_statuslabel();
    // init label for status
    void startMoving_2(int dstfloor);
    // moving for outerbtn s require
    void startMoving();
    // moving for innerbtn s require
    void openDoor();
    // open door
    void closeDoor();
    // close door
signals:
    void isIdle();
    // when idle sent signals for elevator scheduler to addtask
    void door_status_changed(int door_status);//
    void status_changed(int status);//
    void outerButton(int num);
};

#endif // ELEVATOR_H
