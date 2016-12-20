#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mynewclass.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_LoadButton_clicked();

    void on_ForwardButton_clicked();

    void on_BackwardButton_clicked();

private:
    Ui::MainWindow *ui;
    MyNewClass mycsv;
};

#endif // MAINWINDOW_H
