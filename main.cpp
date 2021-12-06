#include "imageeditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageEditor w;
    w.show();
    return a.exec();
}
