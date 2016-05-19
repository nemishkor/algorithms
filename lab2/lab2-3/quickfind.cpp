#include "quickfind.h"

QuickFind::QuickFind(int N)
{
    id = new QList();
    for (int i = 0; i < N; ++i) {
        id->append = i;
    }
}

void QuickFind::connect(int p, int q){ // add connection between p and q
    int pid = id->at(p);
    int qid = id->at(q);
    for (int i = 0; i < id->count(); ++i) {
        if(id->at(i) == pid)
            id[i] = qid;
    }
}

int QuickFind::find(int p){ // component identifier for p (0 to N-1)
    return id->at(p);
}

bool QuickFind::connected(int p, int q){ // return true if p and q in the same component
    return id->at(p) == id->at(q);
}

int QuickFind::count(){ // number of components
    QList<int> components;
    for (int i = 0; i < id->count(); ++i) {
        if(!components.contains(id->at(i)))
            components.append(id->at(i));
    }
    return components.count();
}

