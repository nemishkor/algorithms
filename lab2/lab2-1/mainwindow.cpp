#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(NULL));
    // створюю екземпляри класа QuickFind з 1'000, 10'000, 100'000 кількістю елементів
    //  та створюю 1'000, 10'000, 100'000 відповідно кількість з'єднань відповідно з
    //  рандомними елементами та виводжу номери з'єднань та кількість з'єднань.
    //  Вивід з консолі можна використовувати як файл csv для побудови графіків
    //  у LibreOffice Calc
    //  Запуск ~1 хв.

    /*
    ui->textEdit->append("Quick Find\n");
    for(int i = 1; i < 4; i++){
        ui->textEdit->append(QString("------START FOR N = %1------").arg(QString::number(8000 * i)));
        int N = 8000 * i;
        QuickFind *quickFind = new QuickFind(N);
        int connections = 0;
        for(int i = 0; i < N; i++){
            int p = rand() % N;
            int q = rand() % N;
            if(!quickFind->connected(p,q)){
                connections++;
                quickFind->connect(p,q);
            }
            QString line = QString::number(i + 1);
            line += ",";
            line += QString::number(connections);
            ui->textEdit->append(line);
        }
        ui->textEdit->append("------END------");
        //delete quickFind;
    }
    //*/


    /*
    QTextEdit *textFields[3];
    textFields[0] = ui->textEdit;
    textFields[1] = ui->textEdit_2;
    textFields[2] = ui->textEdit_3;
    for(int i = 1; i < 4; i++){
        int N = 8000 * i;
        QuickUnion *quickUnion = new QuickUnion(N);
        int connections = 0;
        for(int i = 0; i < N; i++){
            int p = rand() % N;
            int q = rand() % N;
            if(!quickUnion->connected(p,q)){
                connections++;
                quickUnion->connect(p,q);
            }
            QString line = QString::number(i + 1);
            line += ",";
            line += QString::number(connections);
            textFields[i]->append(line);
        }
        //delete quickFind;
    }
    //*/

    QTextEdit *textFields[3];
    textFields[0] = ui->textEdit;
    textFields[1] = ui->textEdit_2;
    textFields[2] = ui->textEdit_3;
    for(int i = 0; i < 3; i++){
        int N = 8000 * (i + 1);
        QuickUnion *quickUnion = new QuickUnion(N);
        int connections = 0;
        for(int j = 0; j < N; j++){
            int p = rand() % N;
            int q = rand() % N;
            QString line = QString::number(j + 1);
            line += ",";
            if(!quickUnion->connected(p,q)){

                  connections++;
                  quickUnion->connect(p,q);
            }
            line += QString::number(connections);
            textFields[i]->append(line);
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
