#include <QApplication>

#include "serialport/SerialPortDialog.h"
#include "usersignal/UserSignalDialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //SerialPortDialog dialog;
    UserSignalDialog dialog;
    dialog.show();

    return a.exec();
}
