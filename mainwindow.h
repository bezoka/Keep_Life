#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <vector>

#include "simulation.h"
#include "display_window.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public Simulation, public Display_Window
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void Labels_Update();

private slots:
    void on_People_Button_clicked();

    void on_Food_Button_clicked();

    void Update();

    void Set_Average_Age_Label();
    void Set_World_Age_Label();
    void Set_People_Label();
    void Set_Foods_Label();

    void Set_Pixels();

    void Set_Sex_Labels();

private:
    int Days;
    int Age;

    int m;
    int w;
    int a;

    Ui::MainWindow *ui;

    QString string;

    QTimer *Timer;

};

#endif // MAINWINDOW_H
