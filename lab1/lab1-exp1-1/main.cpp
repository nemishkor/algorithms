#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <QList>
#include "timer.h"
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

int main(int argc, char *argv[])
{
    Timer timer;
    cout << "Enter N: ";
    int N;
    cin >> N;
    cout << endl;

    QList<int> times;
    int allTime = 0;
    QList<int> nums;
    QList<int> cycleTimes;
    int cycleAllTime;
    srand(time(NULL));
    bool findMore;

    for(int i = 0; i < 1000; i++){
        nums.clear();
        findMore = true;
        cycleAllTime = 0;
        cycleTimes.clear();
        while(findMore) {
            timer.start();
            int tmp = rand() % N;
            cycleTimes.append(timer.getTime());
            cout << tmp << " :: " << cycleTimes.last() << endl;
            if(nums.contains(tmp)){
                findMore = false;
            } else {
                nums.append(tmp);
            }
        }
        for (int i = 0; i < cycleTimes.count(); ++i) {
            cycleAllTime += cycleTimes.at(i);
        }
        times.append(cycleAllTime);
    }
    for (int i = 0; i < times.count(); ++i) {
        allTime += times.at(i);
    }
    allTime /= times.count();
    cout << "My time = " << allTime;
    cout << "\n~sqrt(Pi*(" << N << "/2)) = " << sqrt(M_PI * N / 2) << endl;

    return 0;
}
