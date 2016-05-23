#ifndef PERCOLATIONSTATS_H
#define PERCOLATIONSTATS_H

#include "percolation.h"
#include <ctime>
#include <cmath>

class PercolationStats
{
public:
    PercolationStats(int N, int T); // запуск системи просочування розміром NxN, Т раз.
    double mean(); // обчислення середнього значення
    double stddev(); // стандартне відхилення
    double confidenceLo(); // нижня межа довірчого інтервалу
    double confidenceHi(); // верхня межа довірчого інтервалу

    double* x;
    double meanNum;
    int sevX, N, T;
};

#endif // PERCOLATIONSTATS_H
