#include "emergency.h"
#include "ui_emergency.h"

emergency::emergency(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::emergency)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
}

emergency::~emergency()
{
    delete ui;
}
