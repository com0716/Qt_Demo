#include <QApplication>

#include "serialport/SerialPortDialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SerialPortDialog serialportDialog;
    serialportDialog.show();

    return a.exec();
}
