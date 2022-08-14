#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
        {
     ui->setupUi(this);

     this->setLayout(l);

     this->setWindowTitle("Array sorting");

     for(int i = 0; i < 10; i++)
     {
         QTextEdit *t = new QTextEdit("", this);
         QLabel *n = new QLabel("",this);
         QLabel *d = new QLabel("",this);
         QPushButton *b = new QPushButton("", this);

         l->addWidget(t);
         l->addWidget(n);
         l->addWidget(d);
         l->addWidget(b);

         texts->append(t);
         numbers->append(n);
         descripts->append(d);
         buttons->append(b);

         buttons->at(i)->setStyleSheet("font-size: 16px;");
         texts->at(i)->setGeometry(30,80+i*90,1400,50);
         descripts->at(i)->setStyleSheet("font-size: 16px;");
         descripts->at(i)->setGeometry(30,120+i*90,1500,50);
         descripts->at(i)->setText("");
         numbers->at(i)->setGeometry(10,80+i*90,50,50);
         buttons->at(i)->setGeometry(1450, 80+i*90,150,50);
         texts->at(i)->setText("");
         numbers->at(i)->setText(QString::number(i+1));
         buttons->at(i)->setText("\u0421\u0433\u0435\u043d\u0435\u0440\u0438\u0440\u043e\u0432\u0430\u0442\u044c");
         buttons->at(i) ->setObjectName(QString::number(i));
         QObject::connect(buttons->at(i), SIGNAL(clicked()), this, SLOT(toGenerate()));
     }
     for (int i = 0; i < 5; i++)
     {
         QRadioButton *r = new QRadioButton("",this);
         l->addWidget(r);
         radios->append(r);
         radios->at(i)->setGeometry(1610, 55+i*90,300,100);
         radios->at(i)->setObjectName(QString::number(i+10));
     }
     radios->at(0)->setChecked(1);
     radios->at(0)->setText("1.	\u041e\u0442 \u043c\u0430\u043a\u0441\u0438\u043c\u0430\u043b\u044c\u043d\u043e\u0433\u043e \u0441\u0440\u0435\u0434\u043d\u0435\u0433\u043e \u0437\u043d\u0430\u0447\u0435\u043d\u0438\u044f\n \u043c\u0430\u0441\u0441\u0438\u0432\u0430 \u043a \u043c\u0438\u043d\u0438\u043c\u0430\u043b\u044c\u043d\u043e\u043c\u0443.");
     radios->at(1)->setText("2.	\u041e\u0442 \u043c\u0430\u043a\u0441\u0438\u043c\u0430\u043b\u044c\u043d\u043e\u0439 \u0434\u0438\u0441\u043f\u0435\u0440\u0441\u0438\u0438\n \u043a \u043c\u0438\u043d\u0438\u043c\u0430\u043b\u044c\u043d\u043e\u0439.");
     radios->at(2)->setText("3.	\u041e\u0442 \u043c\u0430\u043a\u0441\u0438\u043c\u0430\u043b\u044c\u043d\u043e\u0439 \u0441\u0443\u043c\u043c\u044b \u044d\u043b\u0435\u043c\u0435\u043d\u0442\u043e\u0432\n \u043a \u043c\u0438\u043d\u0438\u043c\u0430\u043b\u044c\u043d\u043e\u0439.");
     radios->at(3)->setText("4.	\u041e\u0442 \u043c\u0430\u043a\u0441\u0438\u043c\u0430\u043b\u044c\u043d\u043e\u0439 \u0440\u0430\u0437\u043d\u043e\u0441\u0442\u0438 \u044d\u043b\u0435\u043c\u0435\u043d\u0442\u043e\u0432\n \u043a \u043c\u0438\u043d\u0438\u043c\u0430\u043b\u044c\u043d\u043e\u0439.");
     radios->at(4)->setText("5.	\u041e\u0442 \u043c\u0430\u043a\u0441\u0438\u043c\u0430\u043b\u044c\u043d\u043e\u0433\u043e \u0441\u0440\u0435\u0434\u043d\u0435\u043a\u0432\u0430\u0434\u0440\u0430\u0442\u0438\u0447\u043d\u043e\u0433\u043e\n \u0437\u043d\u0430\u0447\u0435\u043d\u0438\u044f \u043a \u043c\u0438\u043d\u0438\u043c\u0430\u043b\u044c\u043d\u043e\u043c\u0443.");
    for (int i = 0;i<2; i++)
    {
        QPushButton *bb = new QPushButton("", this);
        l->addWidget(bb);
        bigbuttons->append(bb);
        bigbuttons->at(i)->setGeometry(1610, 60+(i+5)*90,280,70);
        bigbuttons->at(i)->setStyleSheet("font-size: 24px;");
    }

    bigbuttons->at(1) -> setText("\u0421\u0433\u0435\u043d\u0435\u0440\u0438\u0440\u043e\u0432\u0430\u0442\u044c \u0432\u0441\u0451!");
    QObject::connect(bigbuttons->at(1), SIGNAL(clicked()), this, SLOT(toGenerateAll()));
    bigbuttons->at(0) -> setText("\u0421\u043e\u0440\u0442\u0438\u0440\u043e\u0432\u0430\u0442\u044c!");
    QObject::connect(bigbuttons->at(0), SIGNAL(clicked()), this, SLOT(toStartSort()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::toGenerate()
{
    int iter = QObject::sender()->objectName().toUInt();
    massive[iter].generate();
    texts->at(iter)->setText(massive[iter].show());
}
void MainWindow::toGenerateAll()
{
    for (int i = 0; i<10;i++)
    {
       massive[i].generate();
       massive[i].no = i;
       numbers->at(i)->setText(QString::number(i+1));
       texts->at(i)->setText(massive[i].show());
    }
}
void MainWindow::toStartSort()
{
    int check = 10;
    for (int i=0;i<5;i++)
    {
        if (radios->at(i)->isChecked())
        {
            check = i;
        }
    }
    toSort(check);
}
void MainWindow::toSort(int check)
{
    for (int i = 0; i<10;i++)
    {
        switch (check)
        {
        case 0: massive[i].middle();break;
        case 1: massive[i].dispersion();break;
        case 2: massive[i].summary();break;
        case 3: massive[i].difference();break;
        case 4: massive[i].rms();break;
        case 10:break;
        default:break;
        }
    }
    double temp[10];
    int nomber[10];
    for (int i= 0;i<10;i++)
    {
        temp[i] = massive[i].value;
        nomber[i] = i;
    }
    for(int i = 1; i < 10; ++i)
    {
        for(int r = 0; r < 10-i; r++)
        {
            if(temp[r] < temp[r+1])
            {
                // Обмен местами
                int tempor = temp[r];
                int nombertemp = nomber[r];
                temp[r] = temp[r+1];
                nomber[r] = nomber [r+1];
                temp[r+1] = tempor;
                nomber[r+1] = nombertemp;
            }
        }
    }
    for (int i = 0; i<10 ; i++)
    {
        numbers->at(i)->setText(QString::number(nomber[i]+1));
        texts->at(i)->setText(massive[nomber[i]].show());
        switch (check)
        {
        case 0: descripts->at(i)->setText("\u0421\u0440\u0435\u0434\u043d\u0435\u0435 \u0437\u043d\u0430\u0447\u0435\u043d\u0438\u0435: " + QString::number(massive[nomber[i]].value));break;
        case 1: descripts->at(i)->setText("\u0414\u0438\u0441\u043f\u0435\u0440\u0441\u0438\u044f: " + QString::number(massive[nomber[i]].value));break;
        case 2: descripts->at(i)->setText("\u0421\u0443\u043c\u043c\u0430: " + QString::number(massive[nomber[i]].value));break;
        case 3: descripts->at(i)->setText("\u0420\u0430\u0437\u043d\u043e\u0441\u0442\u044c: " + QString::number(massive[nomber[i]].value));break;
        case 4: descripts->at(i)->setText("\u0421\u0440\u0435\u0434\u043d\u0435\u043a\u0432\u0430\u0434\u0440\u0430\u0442\u0438\u0447\u043d\u043e\u0435 \u0437\u043d\u0430\u0447\u0435\u043d\u0438\u0435: " + QString::number(massive[nomber[i]].value));break;
        case 10:descripts->at(i)->setText("\u041e\u0448\u0438\u0431\u043a\u0430 \u0441 \u0432\u044b\u0431\u043e\u0440\u043e\u043c \u0441\u043e\u0440\u0442\u0438\u0440\u043e\u0432\u043a\u0438");break;
        default: descripts->at(i)->setText("\u041e\u0448\u0438\u0431\u043a\u0430 \u0441 \u0432\u044b\u0431\u043e\u0440\u043e\u043c \u0441\u043e\u0440\u0442\u0438\u0440\u043e\u0432\u043a\u0438");break;
        }
    }
}
