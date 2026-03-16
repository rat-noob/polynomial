#include <iostream>
#include <cstdlib>
#include <ctime>
#include "TList.h"  

using namespace std;

int tst() {
    srand(time(nullptr));

    int arr[15];
    for (int i = 0; i < 15; i++) {
        arr[i] = rand() % 30;
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    TList<int*> badPairs;

    for (int i = 0; i < 15 - 1; i++) {
    
        if (arr[i] > arr[i + 1]) {  
            badPairs.push_back(&arr[i]);
        }
        
    }


        TList<int*> temp = badPairs;
        

        while (!temp.empty()) {
            int* ptr = temp.pop_front();
            cout <<  *ptr << *(ptr+1) << endl;

        }

  
    

    return 0;
}