#include "SerialPortDialog.h"

#include <QGridLayout>
#include <QMessageBox>

SerialPortDialog::SerialPortDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("串口通信");
    // 1 控件创建
    pNameLabel = new QLabel("串口号", this);
    pNameComboBox = new QComboBox(this);
    pOpsButton = new QPushButton("打开串口", this);
    pRecvTextEdit = new QTextEdit(this);
    pSendLineEdit = new QLineEdit(this);
    pSendButton = new QPushButton("发送", this);

    // 2 控件初始化
    foreach (auto info, QSerialPortInfo::availablePorts()) {
       pNameComboBox->addItem(info.portName());
    }
    pRecvTextEdit->setEnabled(false);
    pSendLineEdit->setEnabled(false);
    pSendButton->setEnabled(false);

    // 3 界面布局
    QGridLayout *pMainLayout = new QGridLayout(this);
    pMainLayout->addWidget(pNameLabel, 0, 0);
    pMainLayout->addWidget(pNameComboBox, 0, 1);
    pMainLayout->addWidget(pOpsButton, 0, 3);
    pMainLayout->addWidget(pRecvTextEdit, 1, 0, 3, 4);
    pMainLayout->addWidget(pSendLineEdit, 4, 0, 1, 3);
    pMainLayout->addWidget(pSendButton, 4, 3, 1, 1);

    // 4 信号绑定
    connect(pOpsButton, SIGNAL(clicked(bool)), this, SLOT(onOpsButtonClicked()));
    connect(&serialport, SIGNAL(readyRead()), this, SLOT(onSerialPortReadyRead()));
    connect(pSendButton, SIGNAL(clicked(bool)), this, SLOT(onSendButtonClicked()));
}

SerialPortDialog::~SerialPortDialog()
{

}

void SerialPortDialog::onOpsButtonClicked()
{
    if (!serialport.isOpen())
    {
        // 如果串口未打开，打开串口
        serialport.setPortName(pNameComboBox->currentText());
        serialport.setBaudRate(QSerialPort::Baud115200);
        if (!serialport.open(QIODevice::ReadWrite))
        {
            // 打开串口出错，提示错误
            QMessageBox::warning(this, "错误", "串口打开错误:"+serialport.errorString());
            return ;
        }
        pNameComboBox->setEnabled(false);
        pOpsButton->setText("关闭串口");
        pRecvTextEdit->setEnabled(true);
        pSendLineEdit->setEnabled(true);
        pSendButton->setEnabled(true);
        pSendButton->setFocus();
    }
    else
    {
        serialport.close();
        pNameComboBox->setEnabled(true);
        pOpsButton->setText("打开串口");
        pRecvTextEdit->setText("");
        pRecvTextEdit->setEnabled(false);
        pSendLineEdit->setText("");
        pSendLineEdit->setEnabled(false);
        pSendButton->setEnabled(false);
    }
}

void SerialPortDialog::onSerialPortReadyRead()
{
    // 接收数据
    QByteArray data = serialport.readAll();
    pRecvTextEdit->append(data.toHex().toUpper());
}

void SerialPortDialog::onSendButtonClicked()
{
    QString data = pSendLineEdit->text().trimmed();
    if (data == "")
    {
        QMessageBox::warning(this, "警告", "发送内容不能为空！");
        return ;
    }
    // 发送数据
    serialport.write(data.toLocal8Bit());
}
