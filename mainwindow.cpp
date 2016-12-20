#include "mainwindow.h"
#include "mynewclass.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <iostream>
#include <QFormLayout>
#include <QApplication>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LoadButton_clicked()
{  ui->statusBar->showMessage("");
   QString myfilename=QFileDialog::getOpenFileName(this,tr("Open Image List"),"",tr("Image List(*.csv);;All files(*.*)"));


   if(!(myfilename.endsWith(".csv")))
   {ui->statusBar->showMessage("Cannot Open This File!");return;}

   qDebug()<<myfilename;

   mycsv.openfile(myfilename);
     if(mycsv.openfile(myfilename)==-1||mycsv.openfile(myfilename)==-2)
     {ui->statusBar->showMessage("Cannot Open This File!");return;}

     mycsv.setpresuf("pokemon-",".png");
     ui->Captionlabel->setText(mycsv.getcaption(mycsv.locationnum));

     ui->Imagelabel->setPixmap(QPixmap::fromImage(mycsv.getimage(myfilename,mycsv.locationnum)));

}

void MainWindow::on_ForwardButton_clicked()
{
     mycsv.filegoforward(&(mycsv.locationnum));
     mycsv.setpresuf("pokemon-",".png");
     ui->Captionlabel->setText(mycsv.getcaption(mycsv.locationnum));
     ui->Imagelabel->setPixmap(QPixmap::fromImage(mycsv.getimage(mycsv.fname,mycsv.locationnum)));
}

void MainWindow::on_BackwardButton_clicked()
{
     mycsv.filegobackward(&(mycsv.locationnum));
     mycsv.setpresuf("pokemon-",".png");
     ui->Captionlabel->setText(mycsv.getcaption(mycsv.locationnum));
     ui->Imagelabel->setPixmap(QPixmap::fromImage(mycsv.getimage(mycsv.fname,mycsv.locationnum)));
}
