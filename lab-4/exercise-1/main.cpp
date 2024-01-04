#include <iostream>
#include "ArrayList.h"

using namespace std;

int main(){


    ArrayList arr;

     arr.append(99);
        arr.append(27);
        arr.append(14);
        arr.append(42);
        arr.append(72);

    cout << arr << endl;

    // collection.removeFirst();

    cout << arr << endl;

    // collection.removeLast();

    arr.insert(101, 2);
    
    cout << arr << endl;

    // cout << collection.get(1) << endl;
    
    return 0;
}