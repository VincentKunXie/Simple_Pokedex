#ifndef MYNEWCLASS_H
#define MYNEWCLASS_H
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>
#include <QImage>

class MyNewClass
{
private:

    QStringList captions, images;

public:
    int locationnum;
    QString fname;
    MyNewClass();
    int openfile(QString);
    QString getcaption(int);
    QImage getimage(QString,int);
    void filegoforward(int*);
    void filegobackward(int*);
    void setpresuf(QString,QString);
};

#endif // MYNEWCLASS_H
