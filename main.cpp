#include "TP2_Qt.h"
#include <QtWidgets/QApplication>
#include <sstream>
#include <string>
#include <iostream>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TP2_Qt w;
    w.show();
    return a.exec();
}
