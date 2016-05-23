#ifndef PERCOLATION_H
#define PERCOLATION_H

#include <iostream>
using namespace std;

class Percolation
{
public:
    Percolation(int N); // створити сітку NxN заблокованих клітин
    void open(int i, int j); // відкрити заблоковану клітину
    bool isOpen(int i, int j); // перевірка на відкритість?
    bool isFull(int i, int j); // перевірка на заповненість?
    bool percolates(); // перевірка просочування системи?
    void print();

    int opened;
    int N;
    int** net;
};

#endif // PERCOLATION_H
