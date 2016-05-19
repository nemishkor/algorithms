#ifndef QUICKUNION_H
#define QUICKUNION_H

#include <QList>

class QuickUnion // Weighted
{
public:
    QuickUnion(int N);

    QList<int> id; // parent link
    int count;

    void connect(int p, int q); // add connection between p and q
    int find(int i); // component identifier for p (0 to N-1)
    bool connected(int p, int q); // return true if p and q in the same component
};

#endif // QUICKUNION_H
