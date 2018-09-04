#ifndef USERSIGNALDIALOG_H
#define USERSIGNALDIALOG_H

#include <QDialog>
#include <QObject>
#include "QComboBoxDropDown.h"
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>

class UserSignalDialog : public QDialog
{
    Q_OBJECT
public:
    explicit UserSignalDialog(QWidget *parent = nullptr);
    ~UserSignalDialog();

private:
    QLabel *pComboxBoxLabel;
    QComboBoxDropDown *pComboBoxDropDown;
    QTextEdit *pRecvFromChild;
    QPushButton *pOpenFormButton;

private slots:
    void onComboBoxDropDownClicked();
    void onOpenFormButtonClicked();
    void recvString(QString str);
};

#endif // USERSIGNALDIALOG_H
