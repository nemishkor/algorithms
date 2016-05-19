#ifndef QUICKFIND_H
#define QUICKFIND_H

#include <QList>

class QuickFind
{
public:
    QuickFind(int N);

    QList<int> id;

    void connect(int p, int q); // add connection between p and q
    int find(int p); // component identifier for p (0 to N-1)
    bool connected(int p, int q); // return true if p and q in the same component
    int count(); // number of components
};

#endif // QUICKFIND_H
