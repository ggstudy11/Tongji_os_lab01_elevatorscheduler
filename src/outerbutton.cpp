#include "outerbutton.h"

outerbutton::outerbutton(QWidget *parent)
    : QWidget{parent}
{
    this->setFixedSize(300,700);
    for(int i=0;i<2;++i){
        for(int j=0;j<22;j=j+2){
            int num = 20*i + j;
            qDebug()<<num;
            label[10*i+j/2] = new QLabel(this);
            label[10*i+j/2]->setText(QString("%1L").arg(10*i+j/2+1));
            label[10*i+j/2]->setFixedSize(20,10);
            label[10*i+j/2]->move(80*i,25*j+15);
            for(int k=0;k<2;++k){
                btn[num+k] = new QPushButton(this);
                btn[num+k]->setFixedSize(25,50);
                btn[num+k]->move(20+90*i+25*k,25*j);
                btn[num+k]->setCheckable(true);
                //()<<num+k;
                btn[num+k]->setStyleSheet("QPushButton {"
                                            "background-color: white;" // 设置按钮的初始背景颜色为白色
                                            "}"
                                            "QPushButton:checked {"
                                            "background-color: yellow;" // 设置按钮在按下时的背景颜色为黄色
                                            "}"
                                            "QPushButton:pressed {"
                                            "background-color: yellow;" // 设置按钮在按下时的背景颜色为黄色
                                            "}");
                if(k==0){
                    btn[num+k]->setText("↑");
                }else{
                    btn[num+k]->setText("↓");
                }
                connect(btn[num+k], &QPushButton::clicked, this, [=]() {
                    // 在按钮被点击时，调用槽函数并传递目标楼层信息作为参数
                    qDebug()<<10*i+j/2+1;
                    qDebug()<<num+k<<btn[num+k]->isChecked();
                    emit clicked(10*i+j/2+1);
                });
            }
        }
    }
}

void outerbutton::released( int num )
{
    //qDebug()<<num<<"!";
    //qDebug()<<label[num-1]->text();
    //qDebug()<<btn[2*(num-1)]->isChecked();
    if(btn[2*(num-1)]->isChecked())
        btn[2*(num-1)]->setChecked(false);
    else if(btn[2*(num-1)+1]->isChecked())
        btn[2*(num-1)+1]->setChecked(false);
    //qDebug()<<btn[2*(num-1)]->isChecked();
}
