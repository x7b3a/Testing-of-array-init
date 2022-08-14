#include <QTest>
#include <QLineEdit>
#include <QtGui>
#include "array_test.h"
#include "array.h"

Array_test::Array_test(QObject *parent) :
    QObject(parent)
{
}

void Array_test::check_init_array()
{
    Array a;
    for (int i=0;i<50;i++)
        QCOMPARE(a.date[i], 0);
}
void Array_test::generate_min()
{
    Array a;
    for (int j= 0;j<100;j++)
    {
        a.generate();
        for (int i=0;i<50;i++)
        {
            int b;
            b = a.date[i]>-30000?1:0;
            QCOMPARE(b,1);
        }
    }
}
void Array_test::generate_max()
{
       Array a;
       for (int j= 0;j<100;j++)
       {
            a.generate();
            for (int i=0;i<50;i++)
            {
                int b;
                b = a.date[i]<30000?1:0;
                QCOMPARE(b,1);
            }
       }
}
