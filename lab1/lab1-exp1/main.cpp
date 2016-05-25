#include <iostream>
#include <QList>
#include <cstdlib>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <../../timer.h>
#include <../../bigint/BigInteger.hh>
using namespace std;

int main(int argc, char *argv[])
{
    Timer timer;
    cout << "Enter N: ";
    int N;
    cin >> N;
    cout << endl;

    QList<int> nums;
    QList<int> times;
    int allTime = 0;
    srand(time(NULL));
    bool findMore = true;
    while(findMore) {
        timer.start();
        int tmp = rand() % N;
        times.append(timer.getTime());
        cout << N << " :: " << times.last() << endl;
        if(nums.contains(tmp)){
            findMore = false;
        } else {
            nums.append(tmp);
        }
    }

    for (int i = 0; i < times.count(); ++i) {
        allTime += times.at(i);
    }
    cout << "My time = " << allTime;
    cout << "\n~sqrt(Pi*(" << N << "/2)) = " << sqrt(M_PI * N / 2);

    return 0;
}
