#include "mainwindow.h"
#include <QPushButton>
#include <QApplication>
#include <QtWidgets>
#include <QLayout>
#include <QList>
#include <QPainter>
#include "array.h"
#include "smart.h"
#include <QTest>
#include "array_test.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QTest::qExec(new Array_test, argc, argv);
    return a.exec();

}
