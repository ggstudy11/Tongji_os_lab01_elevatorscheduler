/********************************************************************************
** Form generated from reading UI file 'emergency.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMERGENCY_H
#define UI_EMERGENCY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_emergency
{
public:
    QTextEdit *textEdit;

    void setupUi(QWidget *emergency)
    {
        if (emergency->objectName().isEmpty())
            emergency->setObjectName("emergency");
        emergency->resize(400, 300);
        textEdit = new QTextEdit(emergency);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(100, 110, 171, 51));

        retranslateUi(emergency);

        QMetaObject::connectSlotsByName(emergency);
    } // setupUi

    void retranslateUi(QWidget *emergency)
    {
        emergency->setWindowTitle(QCoreApplication::translate("emergency", "Form", nullptr));
        textEdit->setHtml(QCoreApplication::translate("emergency", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt; font-weight:700; color:#aa0000;\">\347\224\265\346\242\257\346\225\205\351\232\234</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class emergency: public Ui_emergency {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMERGENCY_H
