#ifndef CONTAINER_H
#define CONTAINER_H

#include "ArrayList.h"
#include "LinkedList.h"
#include <stdexcept>

struct Container{

    ArrayList<bool> storage;
    int K;

    Container(){
        // By default assume
        // the range of values is 10
        K = 10;
        for (int i  = 0; i < K; i++){
            storage.append(false);
        }
    }

    Container(int n){
        K = n;
        for (int i = 0; i < K; i++){
            storage.append(false);
        }
    }

    void add(int value){
        if (value < 0 || value>= K){
            throw std::logic_error("Out of bounds");
        }
        storage[value] = true;

        //storage.append(value);
        //storage.insertion_sort();
    }


    bool search(int value){
        if (value < 0 || value >= K){
            return false;

        }
        return storage[value];
        //return storage.binary_search(value);
    }


};

#endif