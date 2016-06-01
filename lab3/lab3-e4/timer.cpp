#include "timer.h"

Timer::Timer()
{
    clear();
}


void Timer::end(){
    endTime = clock();
}

void Timer::start(){
    startTime = clock();
}

void Timer::addStep(unsigned int x){
    times[index] = x;
    index++;
}

unsigned int Timer::getTime(){
    return clock() - startTime;
}

unsigned int Timer::getInterval(){
    return endTime - startTime;
}

unsigned int Timer::getAverageX(){
    unsigned int average;
    for(int i = 0; i < (sizeof(times) / sizeof(int)); i++){
        average += times[i];
    }
    return average / (sizeof(times) / sizeof(int));
}

void Timer::addCompare(){
    compares++;
}

void Timer::addSwap(){
    swaps++;
}

void Timer::addAccess(){
    accesses++;
}

void Timer::clearCompares(){
    compares = 0;
}

void Timer::clearSwaps(){
    swaps = 0;
}

void Timer::clearAccesses(){
    accesses = 0;
}

int Timer::getCompares(){
    return compares;
}

int Timer::getSwaps(){
    return swaps;
}

int Timer::getAccesses(){
    return accesses;
}

void Timer::clear(){
    index = 0;
    startTime = 0;
    endTime = 0;
    compares = 0;
    swaps = 0;
    accesses = 0;
    for(int i = 0; i < (sizeof(times) / sizeof(int)); i++){
        times[i] = 0;
    }
}

void Timer::print(){

}
