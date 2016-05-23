#include "percolation.h"

Percolation::Percolation(int N){
    this->N = N;
    opened = 0;
    net = new int* [N];
    for (int i = 0; i < N; ++i) {
        net[i] = new int [N];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            net[i][j] = -1;
        }
    }
}

void Percolation::print(){
    for (int i = 0; i < N; ++i) {
        cout << i << "|";
        for (int j = 0; j < N; j++)
            if (net[i][j] == -1)
                cout << "88";
            else
                if (net[i][j] == 1)
                    cout << "++";
                else
                    cout << "  ";
        cout << endl;
    }
    cout << endl;
}

void Percolation::open(int i, int j){ // відкрити заблоковану клітину
    if(net[i][j] != 0){
        opened++;
        net[i][j] = 0;
    }
}

bool Percolation::isOpen(int i, int j){ // перевірка на відкритість?
    if(net[i][j] == 0)
        return true;
    return false;
}

bool Percolation::isFull(int i, int j){ // перевірка на заповненість?
    if(net[i][j] == 1)
        return true;
    return false;
}

bool Percolation::percolates(){// перевірка просочування системи?
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(net[i][j] == 0 && i == 0)
                net[i][j] = 1;
            if(net[i][j] == 1){
                if(i != 0)
                    if(isOpen(i - 1, j))
                        net[i - 1][j] = 1;
                if(i != N - 1)
                    if(isOpen(i + 1, j))
                        net[i + 1][j] = 1;
                if(j != 0)
                    if(isOpen(i, j - 1))
                        net[i][j - 1] = 1;
                if(j != N - 1)
                    if(isOpen(i, j + 1))
                        net[i][j + 1] = 1;
            }
        }
    }
}
