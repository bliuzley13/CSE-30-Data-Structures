#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "ArrayList.h"
#include "LinkedList.h"
#include <stdexcept>

struct HashTable{

    // You can declare more instance variables here
    ArrayList<LinkedList<int>> storage;
    int K;

    HashTable(){
        K = 10;
        // If you have more instance variables, init them here
        for (int i = 0; i < K; i++){
            storage.append(LinkedList<int>() );
        }
    }

    HashTable(int K){
        this->K = K;
        // If you have more instance variables, init them here
        for (int i = 0; i < K; i++){
            storage.append(LinkedList<int>() );
        }
    }

    void add(int value){
        // This function must be implemented
        if (value < 0){
            throw std::logic_error("Outta Bounds");
        }
        int smth = value % K;
        storage[smth].append(value);
    }


    bool search(int value){
        // This function must be implemented
        if (value < 0){
            return false;
        }
        int smth = value % K;
        return storage[smth].search(value);       
        // return false;
    }

    // You can declare other functions if needed

};

#endif