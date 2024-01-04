#ifndef GOODLIST_H
#define GOODLIST_H

#include <ostream>
#include <stdexcept>
#include  "math.h"

struct GoodList{
    int** data;
    int capacity;
    int count;
    int num_Lists;
    int full_Length;


    GoodList(){
        capacity = 1;
        count = 0;
        //The size below is defaulted at 1000. But 2^(1000) is the precise amount
        data = new int*[1000];
        //This initializes the first array to make sure that its size capacity
        data[0] = new int[capacity];
        num_Lists = 0;
        full_Length = 0;
        // Your code here
    }

    void append(int value){
        // data[count][count] = value;
        // count++;

        // if (count == initcapacity){
            // Meant to double the capacity
            // int oldCapacity = capacity;
            // capacity*=2;

            //copies things
            // for (int i = 0; i < oldCapacity; i++){
            //     temp[i] = data[i];
            // }
        //     while (block[value] < capacity){
        //         int* block = new int[initcapacity];
                
        //         for (int i = 0; i < capacity; i++){
        //             block[i] = i;
        //         }
                
        //         data = data->block;
        //         delete block;
        //     }
        // }

        // Your code here
        //The smaller array set to a certain amount, and it
        //would append to the previous data that already exists
        if (count == capacity){
            capacity *= 2;
            //This adds up a number of a list
            num_Lists++;
            //The new list is made to be larger
            data[num_Lists] = new int[capacity];
            //The count is reset so the index is not out of range
            count = 0;
            data[num_Lists][count] = value;
        }
        else{
            data[num_Lists][count] = value;
        }
        count++;
        full_Length++;

    }

    int& operator[](int index){
        // if (index < 0){
        //     throw std::logic_error("Index Less than 0");
        // }
        // if(index < count) {
        //     int result = data[index];
        //     return result;
        // }
        // else{
        //     throw std::logic_error("Crashes");
        // }
        // try{
        //     if(index > count){
        //         throw std::logic_error("GoodListOutOfBounds");
        //     }
        // }
        // catch(std::logic_error& e){
        //     std::cout << "ArrayListOutOfBounds" << std::endl;
        //     throw e;
        // };
        // return data[index];


        // Your code here
        return data[int(log2(index+1))][int((index+1)-int(pow(2, int(log2(index + 1)))))];
    }

    ~GoodList(){
        //This is made to delete all the pointer arrays and the data array
        for (int i; i < 1000; i++){
            delete[] data[i];
        }
        // delete[] data;                                      //Code made
        // Your code here
    }
};

std::ostream& operator<<(std::ostream& os, GoodList& gl){
    for (int i = 0; i < gl.count; i++){                   //Code made
        os << gl.data[i] << " ";                          //Code made
    }
    // Your code here

    return os;
}


#endif