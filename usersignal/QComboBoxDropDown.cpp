#include "QComboBoxDropDown.h"

QComboBoxDropDown::QComboBoxDropDown(QWidget *parent) : QComboBox(parent)
{

}

void QComboBoxDropDown::mouseReleaseEvent(QMouseEvent *event)
{
    emit clicked(); //通过事件触发信号
    event->accept();
}
