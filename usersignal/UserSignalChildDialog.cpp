#include "UserSignalChildDialog.h"

#include <QMessageBox>
#include <QGridLayout>

UserSignalChildDialog::UserSignalChildDialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("子窗口");
    pSendLineEdit = new QLineEdit(this);
    pSendButton = new QPushButton("发送", this);

    QGridLayout *pMainLayout = new QGridLayout(this);
    pMainLayout->addWidget(pSendLineEdit, 0, 0, 1, 2);
    pMainLayout->addWidget(pSendButton, 0, 2);

    connect(pSendButton, SIGNAL(clicked(bool)), this, SLOT(onSendButtonClicked()));
}

UserSignalChildDialog::~UserSignalChildDialog()
{

}

void UserSignalChildDialog::onSendButtonClicked()
{
    QString data = pSendLineEdit->text().trimmed();
    if (data != "")
    {
        emit sendString(data);
    }
}
