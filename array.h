#ifndef ARRAY_H
#define ARRAY_H
#include <QString>
class Array
{
public:
    Array();
    double date[50];
    int no;
    double value;


    void generate();

    void middle();
    void dispersion();
    void summary();
    void difference();
    void rms();

    QString show();
};
#endif // ARRAY_H
