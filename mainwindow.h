#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPainter>
#include "array.h"
#include <QDebug>
#include <QString>
#include <QApplication>
#include <QtWidgets>
#include <QLayout>
#include <QList>
#include <QRadioButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     Array massive[10];
protected:
    QVBoxLayout *l = new QVBoxLayout(this);
    QList<QTextEdit *> *texts = new QList<QTextEdit *>();
    QList<QLabel *> *descripts = new QList<QLabel *>();
    QList<QLabel *> *numbers = new QList<QLabel *>();
    QList<QPushButton *> *buttons = new QList<QPushButton *>();
    QList<QPushButton *> *bigbuttons = new QList<QPushButton *>();
    QList<QRadioButton *> *radios = new QList<QRadioButton *>();
private:
    Ui::MainWindow *ui;
public slots:
    void toGenerate();
    void toGenerateAll();
    void toStartSort();
    void toSort(int);

};
#endif // MAINWINDOW_H
