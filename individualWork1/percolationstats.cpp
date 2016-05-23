#include "percolationstats.h"

PercolationStats::PercolationStats(int N, int T){ // запуск системи просочування розміром NxN, Т раз.
    x = new double [N];
    this->N = N;
    this->T = T;
    Percolation percolation(N);
    srand( time(0) );
    int i, j;
    for(int n = 0; n < T; n++){
        i = rand() % N;
        j = rand() % N;
        percolation.open(i, j);
        x[n] = percolation.opened / N;
    }
}

double PercolationStats::mean(){ // обчислення середнього значення
    double sum = 0;
    for(int i = 0; i < T; i++){
        sum += x[i];
    }
    return sum / T;
}

double PercolationStats::stddev(){ // стандартне відхилення
    double sum = 0;
    meanNum = mean();
    for(int i = 0; i < T; i++){
        sum += pow(x[i] - meanNum, 2);
    }
    double q = sum / (T - 1);
    return sqrt(q);
}

double PercolationStats::confidenceLo(){ // нижня межа довірчого інтервалу
    meanNum = mean();
    return meanNum - (1.96 * stddev() / sqrt(T));
}

double PercolationStats::confidenceHi(){ // верхня межа довірчого інтервалу
    meanNum = mean();
    return meanNum + (1.96 * stddev() / sqrt(T));

}
