#ifndef TIMER_H
#define TIMER_H

#include <ctime>

class Timer
{
public:
    Timer();
    void start();
    void end();
    void addStep(unsigned int);
    unsigned int getTime();
    unsigned int getInterval();
    unsigned int getAverageX();
    void addCompare();
    void addSwap();
    void addAccess();
    int getCompares();
    int getSwaps();
    int getAccesses();
    void clearCompares();
    void clearSwaps();
    void clearAccesses();
    void clear();
    void print();

private:
    unsigned int times[1000];
    int index;
    unsigned int startTime, endTime, compares, swaps, accesses;
};

#endif // TIMER_H
