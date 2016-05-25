#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

/* Розробіть алгоритм для задачі пошуку четвірок з нульовою сумою. */

int main(int argc, char *argv[])
{
    unsigned int arraySize;
    cout << "Enter size of array: ";
    cin >> arraySize;
    int nums[arraySize];
    srand(time(NULL));
    for(int i = 0; i < arraySize; i++){
        nums[i] = (rand() % 100) - 50;
    }

    cout << endl << "numers[";
    for(int i = 0; i < arraySize; i++){
        cout << nums[i];
        if(i < arraySize - 1){
            cout << ", ";
        }
    }
    cout << "]" << endl;
    for(int i = 0; i < arraySize - 4; i++){
        for(int j = i + 1; j < arraySize - 3; j++){
            for(int k = j + 1; k < arraySize - 2; k++){
                for(int p = k + 1; p < arraySize; p++){
                    if((nums[i] + nums[j] + nums[k] + nums[p]) == 0)
                        cout << nums[i] << " + " << nums[j] << " + " << nums[k] << " + " << nums[p] << " = 0" << endl;
                }
            }
        }
    }

    return 0;
}
