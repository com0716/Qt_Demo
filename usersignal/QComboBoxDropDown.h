#ifndef QCOMBOBOXDROPDOWN_H
#define QCOMBOBOXDROPDOWN_H

#include <QObject>
#include <QComboBox>
#include <QMouseEvent>

class QComboBoxDropDown : public QComboBox
{
    Q_OBJECT
public:
    explicit QComboBoxDropDown(QWidget *parent = nullptr);

protected:
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void clicked(); // 自定义信号
};

#endif // QCOMBOBOXDROPDOWN_H
