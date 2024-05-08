#ifndef EMERGENCY_H
#define EMERGENCY_H

#include <QWidget>

namespace Ui {
class emergency;
}
/*
 *  for emergency window
 *  when press the btn for emergency it pops out
*/
class emergency : public QWidget
{
    Q_OBJECT

public:
    explicit emergency(QWidget *parent = nullptr);
    ~emergency();

private:
    Ui::emergency *ui;
};

#endif // EMERGENCY_H
