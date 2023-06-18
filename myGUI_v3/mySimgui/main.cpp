#include <QApplication>

#include "initdialog.h"
#include "simwindow1.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //调用第一个窗口，选择需要监控的无人艇数量
    InitDialog india;
    india.show();

    return a.exec();

}
