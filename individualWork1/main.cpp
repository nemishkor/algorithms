#include <QCoreApplication>
#include <stdlib.h>
#include <iostream>
#include "percolation.h"
#include "percolationstats.h"
#include "timer.h"
using namespace std;

int main(int argc, char *argv[])
{
//    Percolation percolation(8);
//    percolation.print();
//    percolation.open(0, 2);
//    percolation.open(0, 3);
//    percolation.open(0, 4);
//    percolation.open(1, 0);
//    percolation.open(1, 3);
//    percolation.open(1, 4);
//    percolation.open(1, 5);
//    percolation.open(1, 6);
//    percolation.open(1, 7);
//    percolation.open(2, 0);
//    percolation.open(2, 1);
//    percolation.open(2, 2);
//    percolation.open(2, 5);
//    percolation.open(2, 6);
//    percolation.open(3, 2);
//    percolation.open(3, 3);
//    percolation.open(3, 5);
//    percolation.open(3, 6);
//    percolation.open(3, 7);
//    percolation.open(4, 1);
//    percolation.open(4, 2);
//    percolation.open(4, 3);
//    percolation.open(4, 5);
//    percolation.open(4, 6);
//    percolation.open(5, 1);
//    percolation.open(5, 6);
//    percolation.open(5, 7);
//    percolation.open(6, 0);
//    percolation.open(6, 2);
//    percolation.open(6, 4);
//    percolation.open(6, 5);
//    percolation.open(6, 6);
//    percolation.open(6, 7);
//    percolation.open(7, 0);
//    percolation.open(7, 1);
//    percolation.open(7, 2);
//    percolation.open(7, 3);
//    percolation.open(7, 5);
//    percolation.open(7, 5);
//    percolation.percolates();
//    percolation.print();
    Timer timer;
    timer.start();
    PercolationStats percolationStats(8, 10);
    timer.end();
    cout << timer.getInterval() << endl;
    return 0;
}
