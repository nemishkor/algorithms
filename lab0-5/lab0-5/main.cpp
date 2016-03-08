#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "timer.h"
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

int main(int argc, char *argv[])
{
    /* general things */

    Timer timer;
    BigInteger x;
    int timeout = 100; // max time for run algorithm in ms
    int algorithmTime = 0, cycleTime, severalCycleTime;
    bool debug = true;
    int numberOfCycles = 1000;





    /* things for current allgorithm */

    BigInteger randomNumber;
    unsigned int severalLength = 2;
    unsigned int length = 2; // length of our random number
    for(; algorithmTime < timeout;){

        // generate var bigInteger x
        randomNumber = rand() % 10;
        for(int k = 0; k < length - 1; k++){
            int random = rand() % 10;
            randomNumber *= 10;
            randomNumber += random;
        }

        if(debug){
            cout << "length = " << length << endl;
            cout << "randomNumber = " << randomNumber << endl;
        }

        severalCycleTime = 0;
        for (int i = 0; i < numberOfCycles; ++i) { // find sereval time
            x = randomNumber;
            timer.start(); // start cycle
            x = x * x;
            cycleTime = timer.getTime(); // end cycle
            severalCycleTime += cycleTime;
        }
        severalCycleTime /= numberOfCycles;

        algorithmTime += severalCycleTime;

        if(debug){
            cout << "several time of cycle = " << severalCycleTime << endl;
            cout << "time of algorithm = " << algorithmTime << endl << "----------" << endl;
        }

        length *= 2; // j=0 -> 2; j=1 -> 4; j=2 -> 8; j=3 -> 16;
    }
    severalLength /= numberOfCycles;
    cout << endl << "timeout = " << timeout << " (max time for algorithm)" << endl;
    cout << "last X = " << x << endl;
    cout << "several length = " << severalLength << endl;
    return 0;
}
