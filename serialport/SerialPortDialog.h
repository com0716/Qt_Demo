#ifndef SERIALPORTDIALOG_H
#define SERIALPORTDIALOG_H

#include <QDialog>

#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>

#include <QSerialPort>
#include <QSerialPortInfo>


class SerialPortDialog : public QDialog
{
    Q_OBJECT
public:
    SerialPortDialog(QWidget *parent = nullptr);
    ~SerialPortDialog();

private slots:
    void onOpsButtonClicked();
    void onSerialPortReadyRead();
    void onSendButtonClicked();

private:
    QLabel *pNameLabel;
    QComboBox *pNameComboBox;
    QPushButton *pOpsButton;

    QTextEdit *pRecvTextEdit;

    QLineEdit *pSendLineEdit;
    QPushButton *pSendButton;

    QSerialPort serialport;
};

#endif // SERIALPORTDIALOG_H
