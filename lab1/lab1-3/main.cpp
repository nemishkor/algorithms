#include <iostream>
#include <QtAlgorithms>
#include <QList>
#include <cmath>

using namespace std;

/* Напишіть програму, для знаходження в заданому масиві a[] з N
значень double найближчу пару – тобто два значення, різниця яких
не більше різниці для будь-якої іншої пари (за абсолютною
величиною). Час виконання програми повинен бути лінійно-
логарифмічним в гіршому випадку. */

int main(int argc, char *argv[])
{
    unsigned int arraySize;
    cout << "Enter size of array: ";
    cin >> arraySize;
    QList<double> nums;
    srand((unsigned)time(NULL));
    for(int i = 0; i < arraySize; i++){
        double number = (double)rand();
        nums.append(number );
    }

    cout << endl << "numers[";
    for(int i = 0; i < nums.count(); i++){
        cout << nums.at(i);
        if(i < arraySize - 1){
            cout << ", ";
        }
    }
    cout << "]" << endl;
    qSort(nums.begin(), nums.end());
    cout << "Sorted array " << endl << "numers[";
    for(int i = 0; i < arraySize; i++){
        cout << nums.at(i);
        if(i < arraySize - 1){
            cout << ", ";
        }
    }
    cout << "]" << endl << endl;

    return 0;
}
