#include <QApplication>

#include "initdialog.h"
#include "simwindow1.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    InitDialog india;
    india.show();

    return a.exec();

}
