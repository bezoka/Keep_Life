#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int i=0; i<10000; i++)
    Foods.resize(Foods.size()+1);

    for(int i=0; i<10; i++)
    People.resize(People.size()+1);

    Simulate();

    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(Update()));
    Timer->start(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_People_Button_clicked()
{
    for(int i=0; i<1; i++)
    People.resize(People.size()+1);
    string.setNum(People.size());
    ui->People_Label->setText(string);
}

void MainWindow::on_Food_Button_clicked()
{
    for(int i=0; i<100; i++)
    Foods.resize(Foods.size()+1);
    string.setNum(Foods.size());
    ui->Foods_Label->setText(string);
}


void MainWindow::Update()
{
    Simulate();

    Labels_Update();
}


void MainWindow::Labels_Update()
{
    Set_Average_Age_Label();
    Set_World_Age_Label();
    Set_People_Label();
    Set_Foods_Label();

    Set_Sex_Labels();

    Set_Pixels();

    Handling();

    Display(); // from Display_Window class
}


void MainWindow::Set_Average_Age_Label()
{
    a=0;

    for(unsigned int i=0; i<People.size(); i++)
    {
          a += People[i].Get_States().Get_Age();
    }

    a = a/People.size();

    string.setNum(a);

    ui->Average_Age_Label->setText(string);
}


void MainWindow::Set_World_Age_Label()
{
    Days++;

    if(Days>=365)
    {
        Days = 0;
        Age++;
    }

    string.setNum(Age);
    ui->World_Age_Label->setText(string);
}


void MainWindow::Set_People_Label()
{
    string.setNum(People.size());
    ui->People_Label->setText(string);
}


void MainWindow::Set_Foods_Label()
{
    string.setNum(Foods.size());
    ui->Foods_Label->setText(string);
}


void MainWindow::Set_Pixels()
{
    for(unsigned int i=0; i<People.size(); i++)
    {
        Set_People_Pixels( People[i].Get_Position().Get_x(), People[i].Get_Position().Get_y() );
    }

    for(unsigned int i=0; i<Foods.size(); i++)
        Set_Foods_Pixels( Foods[i].Get_Position().Get_x(), Foods[i].Get_Position().Get_y() );
}


void MainWindow::Set_Sex_Labels()
{
    m=0;
    w=0;

    for(unsigned int i=0; i<People.size(); i++)
    {
        if(People[i].Get_States().Get_Sex()=="Man")
        {
            m++;
        }

        if(People[i].Get_States().Get_Sex()=="Woman")
        {
            w++;
        }
    }
    string.setNum(m);
    ui->Men_Value_Label->setText(string);
    string.setNum(w);
    ui->Women_Value_Label->setText(string);
}
