#include "array.h"
#include <iostream>
#include <ctime>
#include <QDebug>
#include <math.h>
#include <QRandomGenerator>
Array::Array()
{
    for (int i=0;i<50;i++)
    {
        date[i] = 0;
    }
     value = 0;
}
 void Array::generate()
 {
 QRandomGenerator generator;
     for (int i=0;i<50;i++)
     {
         srand( time( NULL ) );
         //date[i] = -RAND_MAX/2+(double)(rand())+(double)(rand())/RAND_MAX;
         //date[i] = -RAND_MAX/2 + qrand();
         date[i] = QRandomGenerator::global()->bounded(-rand(), rand());
        // qDebug() << date[i];
     }
     date[0]=QRandomGenerator::global()->bounded(-rand(),  rand());
 }

void Array::middle()
{
    value = 0;
    for (int i=0;i<50;i++)
    {
        value+=date[i];
    }
    value = value/50;
}
void Array::summary()
{
    value=0;
    for (int i=0;i<50;i++)
    {
        value+=date[i];
    }
}
void Array::difference()
{
    value=0;
    for (int i=0;i<50;i++)
    {
        value-=date[i];
    }
}
void Array::rms()
{
    value=0;
    double disp_mid=0;
    for (int i=0;i<50;i++)
    {
        disp_mid+=date[i];
    }
    disp_mid /=50;
    for (int i=0;i<50;i++)
    {
        value+=(date[i]-disp_mid)*(date[i]-disp_mid);
        //qDebug() <<"value:"<<i <<value;
    }
    value = sqrt(value/50);
}

void Array::dispersion()
{
    value=0;
    double disp_mid=0;
    for (int i=0;i<50;i++)
    {
        disp_mid+=date[i];
    }
    disp_mid /=50;
    //qDebug() <<"dispmid:"<<disp_mid;
    for (int i=0;i<50;i++)
    {
        value+=(date[i]-disp_mid)*(date[i]-disp_mid);
        //qDebug() <<"value:"<<i <<value;
    }
    value/=50;
}

QString Array::show()
{
    QString sh = "";
    for (int i=0;i<50;i++)
    {
        sh+=QString::number(date[i])+" ";
    }
    return sh;
}
