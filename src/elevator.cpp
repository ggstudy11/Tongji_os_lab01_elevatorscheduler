#include "elevator.h"
#include <QTimer>
Elevator::Elevator(QWidget *parent)
    : QWidget{parent},door_status(0),status(0),currentFloor(1)
{
    this->setFixedSize(150,800);
    init_elevator();
    init_positionlabel();
    init_doorlabel();
    init_embtn();
    init_elevator_statuslabel();
    init_innerbtn();
    init_btn_door();
    connect(this, &Elevator::door_status_changed, this, &Elevator::update_doorstatus_label);
    connect(this,&Elevator::status_changed,this,&Elevator::update_status_label);
}

void Elevator::moveTo(){
    QPushButton *clickedBtn = qobject_cast<QPushButton*>(sender()); // change the signal into the point of clicked btn
    if (clickedBtn) {
        if(status == 0||status == 4||status == 3){
            clickedBtn->setChecked(false);
            if(innerbtn[currentFloor-1]->isChecked()){
                innerbtn[currentFloor-1]->setChecked(false);
            }
            return;
        }// in these status can't work
        else{
            int dstfloor = clickedBtn->text().toInt();
            taskList.push(dstfloor);
            qDebug() << "Button pressed for floor" << dstfloor;
        }
    }
    if(!isRunning()){
        startMoving();
    }
}

/*
 * when door is open waiting for door close
 * when tasklist empty emit signals
 * recuivse to ensure task is figured out one by one
*/

void Elevator::startMoving() {
    if(door_status == 1){
        QTimer::singleShot(0, this, [=]() { startMoving(); });
        return ;
    }
    if (taskList.empty()) {
        status = 0;
        emit status_changed(0);
        emit isIdle();
        return;
    }
    int dstfloor = taskList.front();
    taskList.pop();
    status = 1;
    emit status_changed(status);
    int direction = (dstfloor > currentFloor) ? 1 : -1;
    if (currentFloor == dstfloor) {
        if(innerbtn[currentFloor-1]->isChecked()){
            innerbtn[currentFloor-1]->setChecked(false);
        }
        qDebug() << "Arrived at floor" << dstfloor;
        openDoor();
        closeDoor();
        startMoving();
    }
    else{
        QTimer *moveTimer = new QTimer(this);
        connect(moveTimer, &QTimer::timeout, this, [=]()mutable {
            if(status == 0){
                moveTimer->stop();
                moveTimer->deleteLater();
                qDebug()<<"emergency";
            }
            currentFloor += direction;
            elevator->setValue(currentFloor);
            if (currentFloor == dstfloor) {
                moveTimer->stop();
                moveTimer->deleteLater();
                if(innerbtn[currentFloor-1]->isChecked()){
                    innerbtn[currentFloor-1]->setChecked(false);
                }
                qDebug() << "Arrived at floor" << dstfloor;
                openDoor();
                closeDoor();
                startMoving();
            }
        });
        moveTimer->start(500);
    }
    qDebug() << "Going to floor" << dstfloor;
}

void Elevator::update_position_label(int value)
{
    //QString text = QString("电梯位于: %1L").arg(value);
    //positionlabel->setText(text);
    plabel->display(value);
}

bool Elevator::isRunning()
{
    if(status == 1)return true;
    return false;
}

void Elevator::addTask(int dstFloor)
{
    startMoving_2(dstFloor);
    qDebug()<<status;
}

void Elevator::openDoor()
{
    emit door_status_changed(1);
    QTime dieTime = QTime::currentTime().addMSecs(1000);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Elevator::closeDoor()
{
    emit door_status_changed(0);
}


void Elevator::update_doorstatus_label(int door_status)
{
    if(door_status == 1)
        doorlabel->setText("开门");
    else
        doorlabel->setText("关门");
}

void Elevator::emStop()
{
    status = 4;
    emit status_changed(status);
    emergency* newwindow = new emergency();
    newwindow->show();
}

void Elevator::update_status_label(int status)
{
    if(status==0){
        elevator_status->setText("空闲");
    }else if(status == 1){
        elevator_status->setText("运行");
    }else if(status == 2){
        elevator_status->setText("等待");
    }else if(status == 4){
        elevator_status->setText("故障");
    }else if(status == 3){
        elevator_status->setText("响应");
    }
}

void Elevator::btn_openDoor()
{
    if(status==1||status == 3)return;
    door_status = 1;
    emit door_status_changed(door_status);
    QTimer::singleShot(2000, this, &Elevator::btn_closeDoor);
}

void Elevator::btn_closeDoor()
{
    if(status==1)return;
    door_status = 0;
    emit door_status_changed(door_status);
}

void Elevator::init_btn_door()
{
    btn_open_door = new QPushButton(this);
    btn_open_door->setFixedSize(50,25);
    btn_open_door->move(50,650);
    btn_open_door->setText("开门");
    connect(btn_open_door,&QPushButton::clicked,this,&Elevator::btn_openDoor);
    btn_close_door = new QPushButton(this);
    btn_close_door->setFixedSize(50,25);
    btn_close_door->move(100,650);
    btn_close_door->setText("关门");
    connect(btn_close_door,&QPushButton::clicked,this,&Elevator::btn_closeDoor);
}

void Elevator::init_elevator()
{
    elevator = new QSlider(Qt::Vertical,this);
    elevator->setFixedHeight(500);
    elevator->setRange(1,20);
    elevator->setValue(1);
    elevator->setStyleSheet("QSlider::groove:vertical {"
                            "border: 1px solid #999999;"
                            "background: white;"
                            "margin: 0px 0px;"
                            "}"
                            "QSlider::handle:vertical {"
                            "background: blue;"
                            "border: 1px solid blue;"
                            "width: 20px;"
                            "height: 20px;"
                            "margin: -2px 0px;"
                            "border-radius: 5px;"
                            "}");
    elevator->move(25,75);
    connect(elevator, &QSlider::valueChanged, this, &Elevator::update_position_label);
}

void Elevator::startMoving_2(int dstfloor)
{
    if(door_status == 1){
        QTimer::singleShot(0, this, [=]() { startMoving_2(dstfloor); });
        return ;
    }
    status = 3;
    emit status_changed(status);
    int direction = (dstfloor > currentFloor) ? 1 : -1;
    if (currentFloor == dstfloor) {
        emit outerButton(dstfloor);
        status = 2;
        emit status_changed(2);
        qDebug() << "Arrived at floor" << dstfloor;
        openDoor();
        closeDoor();
    }
    else{
        QTimer *moveTimer = new QTimer(this);
        connect(moveTimer, &QTimer::timeout, this, [=]() {
            if(status == 0){
                moveTimer->stop();
                moveTimer->deleteLater();
                qDebug()<<"emergency";
            }
            currentFloor += direction;
            elevator->setValue(currentFloor);
            if (currentFloor == dstfloor) {
                moveTimer->stop();
                moveTimer->deleteLater();
                status = 2;
                emit status_changed(2);
                emit outerButton(dstfloor);
                qDebug() << "Arrived at floor" << dstfloor;
                openDoor();
                closeDoor();
            }
        });
        moveTimer->start(500);
    }
    qDebug() << "Going to floor" << dstfloor;
}

void Elevator::init_positionlabel()
{
    plabel = new QLCDNumber(this);
    plabel->setStyleSheet("QLCDNumber {"
                          "background-color: black;"
                          "color: red;"
                          "border: 2px solid gray;"
                          "border-radius: 5px;"
                          "}");
    plabel->setMode(QLCDNumber::Dec);
    plabel->move(60,0);
    plabel->setFixedSize(80,50);
    plabel->display(1);
}

void Elevator::init_doorlabel()
{
    doorlabel = new QLabel(this);
    doorlabel->setText("关门");
    doorlabel->move(50,575);
    doorlabel->setFixedSize(100,50);
}

void Elevator::init_embtn()
{
    embtn = new QPushButton(this);
    embtn->setText("报警");
    embtn->move(50,675);
    embtn->setFixedSize(100,50);
    connect(embtn,&QPushButton::clicked,this,&Elevator::emStop);
}

void Elevator::init_innerbtn()
{
    for(int col=0;col<2;++col){
        for(int row=0;row<10;++row){
            int num = col*10+row;
            innerbtn[num] = new QPushButton(QString("%1").arg(num + 1),this);
            innerbtn[num]->setFixedSize(50,50);
            innerbtn[num]->move(col*50+55,row*50+75);
            innerbtn[num]->setStyleSheet("QPushButton {"
                                         "background-color: white;"
                                         "}"
                                         "QPushButton:checked {"
                                         "background-color: yellow;"
                                         "}"
                                         "QPushButton:pressed {"
                                         "background-color: yellow;"
                                         "}");
            connect(innerbtn[num], &QPushButton::clicked, this, &Elevator::moveTo);
            innerbtn[num]->setCheckable(true);// keep when pressed
        }
    }
}

void Elevator::init_elevator_statuslabel()
{
    elevator_status = new QLabel(this);
    elevator_status->setText("空闲");
    elevator_status->move(100,575);
    elevator_status->setFixedSize(100,50);
}

bool Elevator::isfree()
{
    if(status == 0)return true;
    return false;
}

int Elevator::currentPosition()
{
    return currentFloor;
}
