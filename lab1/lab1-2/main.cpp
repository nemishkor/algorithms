#include <iostream>
#include <QtAlgorithms>
#include <QList>

using namespace std;

int main(int argc, char *argv[])
{
    unsigned int arraySize;
    cout << "Enter size of array: ";
    cin >> arraySize;
    QList<int> nums;
    srand(time(NULL));
    for(int i = 0; i < arraySize; i++){
        nums.append((rand() % 100) - 50);
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

    int count = 0;
    for(int i = 0; i < nums.count(); i++){
        QList<int>::iterator it = NULL;
        it = qBinaryFind(nums.begin(), nums.end(), nums.at(i) * -1);
        if(it != nums.end()){
            cout << nums.at(i) << " and " << (*it) << endl;
            count++;
        }
    }
    cout << "count = " << count / 2 << endl;

    return 0;
}
