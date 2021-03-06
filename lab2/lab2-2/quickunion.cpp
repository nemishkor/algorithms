#include "quickunion.h"

QuickUnion::QuickUnion(int N)
{
    id = new QList();
    for (int i = 0; i < N; ++i) {
        id->append(i);
    }
}

void QuickUnion::connect(int p, int q){ // add connection between p and q
    int i = find(p);
    int j = find(q);
    id[i] = j;
}

int QuickUnion::find(int i){ // ROOT component identifier for p (0 to N-1)
    while(i != id->at(i))
        i = id->at(i);
    return i;
}

bool QuickUnion::connected(int p, int q){ // return true if p and q in the same component
    return find(p) == find(q);
}

int QuickUnion::count(){ // number of components
    QList<int> components;
    for (int i = 0; i < id->count(); ++i) {
        if(!components->contains(find(i)))
            components.append(find(i));
    }
    return components.count();
}
