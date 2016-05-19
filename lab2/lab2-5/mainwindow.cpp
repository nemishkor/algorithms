#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile inputFile('commands.txt');
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QString line = in.readLine();
       QStringList command = line.split(' ');
       QuickFind quickFind((int)command.at(0));
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          switch((int)command.at(0)){
          case 1:
              int p = (int)command.at(1);
              int q = (int)command.at(2);
              if(!quickFind.connected(p, q))
                  quickFind.connect(p, q);
              break;
          case 2:
              int p = (int)command.at(1);
              int q = (int)command.at(2);
              if(!quickFind.connected(p, q))
                  quickFind.connect(p, q);
              break;
          case 2:
              break;
          }
       }
       inputFile.close();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
