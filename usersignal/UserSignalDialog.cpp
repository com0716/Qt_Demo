#include "UserSignalDialog.h"

#include <QMessageBox>
#include <QGridLayout>

#include "UserSignalChildDialog.h"

UserSignalDialog::UserSignalDialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("自定义信号");
    resize(400, 300);

    // 创建控件
    pComboxBoxLabel = new QLabel("下拉更新", this);
    pComboBoxDropDown = new QComboBoxDropDown(this);
    pRecvFromChild = new QTextEdit(this);
    pOpenFormButton = new QPushButton("新建窗口", this);

    // 布局
    QGridLayout *pMainLayout = new QGridLayout(this);
    pMainLayout->addWidget(pComboxBoxLabel, 0, 0);
    pMainLayout->addWidget(pComboBoxDropDown, 0, 1);
    pMainLayout->addWidget(pRecvFromChild, 1, 0, 3, 3);
    pMainLayout->addWidget(pOpenFormButton, 4, 1, 1, 1);

    // 信号和槽函数绑定
    connect(pComboBoxDropDown, SIGNAL(clicked()), this, SLOT(onComboBoxDropDownClicked()));
    connect(pOpenFormButton, SIGNAL(clicked(bool)), this, SLOT(onOpenFormButtonClicked()));
}

UserSignalDialog::~UserSignalDialog()
{

}

void UserSignalDialog::onComboBoxDropDownClicked()
{
    QMessageBox::information(this, "提示", "ComboBox被点击，启动下拉更新功能！");
}

void UserSignalDialog::onOpenFormButtonClicked()
{
    // 创建子窗口、绑定信号和槽函数、运行子窗口
    UserSignalChildDialog dialog;
    connect(&dialog, SIGNAL(sendString(QString)), this, SLOT(recvString(QString)));
    dialog.exec();
}

void UserSignalDialog::recvString(QString str)
{
    pRecvFromChild->append(str);
}

