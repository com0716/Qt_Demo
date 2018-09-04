#ifndef USERSIGNALCHILDDIALOG_H
#define USERSIGNALCHILDDIALOG_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class UserSignalChildDialog : public QDialog
{
    Q_OBJECT
public:
    explicit UserSignalChildDialog(QWidget *parent = nullptr);
    ~UserSignalChildDialog();

signals:
    void sendString(QString str);

private:
    QLineEdit *pSendLineEdit;
    QPushButton *pSendButton;

private slots:
    void onSendButtonClicked();
};

#endif // USERSIGNALCHILDDIALOG_H
