#ifndef OUTERBUTTON_H
#define OUTERBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
class outerbutton : public QWidget
{
    Q_OBJECT
public:
    explicit outerbutton(QWidget *parent = nullptr);
private:
    QPushButton *btn[40];
    QLabel      *label[20];
public slots:
    void released(int num);
signals:
    void clicked(int dstfloor);
};

#endif // OUTERBUTTON_H
