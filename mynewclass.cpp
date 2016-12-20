#include "mynewclass.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>


MyNewClass::MyNewClass()
{
 locationnum=0;
}

int MyNewClass::openfile(QString myfilename)
{
    QFile imagelist(myfilename);
    if (!imagelist.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return -1;
    }

    QTextStream in(&imagelist);


    while (!in.atEnd())
    {
        QString line= in.readLine();
        QStringList list=line.split(",");
        if(list.size()==2)
        {
            captions<<list[1];
            images<<list[0];
        }
        else
            return -2;
    }

    return 1;
}

QString MyNewClass::getcaption(int i)
{   QString number;

    number= QString::number(locationnum+1);


    QString result = "( " + number +" of 14 ) "+ captions[i];

    return result;
}

QImage MyNewClass::getimage(QString f, int i)
{
    QString image_name = QFileInfo(f).absolutePath() + "/" + images[i];

    QImage img(image_name);
    QImage *imgptr=new QImage;
    *imgptr=img.scaled(300,300,Qt::KeepAspectRatio);
    fname=f;
    return *imgptr;
}

void MyNewClass::filegoforward(int *num)
{
    num=&locationnum;
    *num=*num+1;
    if(*num>13)
    *num=0;

}

void MyNewClass::filegobackward(int *num)
{
    num=&locationnum;
    *num=*num-1;
    if(*num<0)
    *num=13;
}

void MyNewClass::setpresuf(QString pre, QString suf)
{
    if(images[0]!="pokemon-001bulbasaur.png")
    {
        for(int i=0;i<14;i++)
       {
           images[i]= pre+images[i]+suf;
       }
    }
}


