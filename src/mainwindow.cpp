#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setFixedSize(1000,800);
    ui->setupUi(this);
    init_outerbtn();
    init_elevator();
    setWindowTitle("电梯调度");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onClicked(int dstfloor)
{
    qDebug()<<"Received"<<dstfloor;
    int distance = 20;
    bool flag = 0;
    int num = 0;
    for(int i=0;i<5;++i){
        if(elevator[i]->isfree()){
            if(abs(elevator[i]->currentPosition()-dstfloor)<distance){
                distance =abs(elevator[i]->currentPosition()-dstfloor);
                num = i;
            }
            flag = 1;
        }
    }
    if(flag){
        elevator[num]->addTask(dstfloor);
    }else{
        outerTaskList.push(dstfloor);
    }
}

void MainWindow::receivedIdle()
{
    if(outerTaskList.empty())return;
    while(!outerTaskList.empty()){
        int distance = 20;
        int num = 0;
        bool flag = false;
        int dstfloor = outerTaskList.front();
        outerTaskList.pop();
        for(int i=0;i<5;++i){
            if(elevator[i]->isfree()){
                if(abs(elevator[i]->currentPosition()-dstfloor)<distance){
                    distance =abs(elevator[i]->currentPosition()-dstfloor);
                    num = i;
                    flag = true;
                }
            }
        }
        if(flag)
            elevator[num]->addTask(dstfloor);
        else
            break;
    }
}

void MainWindow::init_elevator()
{
    for(int i=0;i<5;++i){
        elevator[i] = new Elevator(this);
        elevator[i]->move(150*i,0);
        connect(elevator[i],&Elevator::isIdle,this,&MainWindow::receivedIdle);
        connect(elevator[i],&Elevator::outerButton,outerbtn,&outerbutton::released);
    }
}

void MainWindow::init_outerbtn()
{
    outerbtn = new outerbutton(this);
    outerbtn->move(800,50);
    connect(outerbtn,&outerbutton::clicked,this,&MainWindow::onClicked);
}
