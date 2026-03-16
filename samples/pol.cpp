#include "Polynomial.h"
#include <iostream>


using namespace std;
int main() {
    
    Monom m1(2.5, 2, 1, 0);   
    Monom m2(3.0, 0, 2, 1);   
    Monom m3(1.0, 1, 0, 0);   
    Monom m4(4.0, 0, 0, 0);   

    
    Polynomial p1;
    p1.addMonom(m1);
    p1.addMonom(m2);
    p1.addMonom(m3);

    Polynomial p2;
    p2.addMonom(m4);
    p2.addMonom(m3);

    cout << "p1 = ";
    p1.print();  

    cout << "p2 = ";
    p2.print();  

    
    Polynomial sum = p1 + p2;
    cout << "p1 + p2 = ";
    sum.print();  

    
    Polynomial diff = p1 - p2;
    cout << "p1 - p2 = ";
    diff.print();  

    
    Polynomial prod = p1 * p2;
    cout << "p1 * p2 = ";
    prod.print();  

    
    double val = p1.evaluate(2.0, 1.0, 3.0);
    cout << "p1(2,1,3) = " << val << endl;









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
        cout << *ptr <<" "<< *(ptr + 1) << endl;

    }

    return 0;
}