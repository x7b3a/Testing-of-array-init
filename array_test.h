#ifndef TEST_SMART_H
#define TEST_SMART_H

#include <QObject>

class Array_test : public QObject
{
    Q_OBJECT
public:
    explicit Array_test(QObject *parent = 0);

private slots: // должны быть приватными
    void check_init_array();
    void generate_min();
    void generate_max();

};

#endif // TEST_SMART_H
