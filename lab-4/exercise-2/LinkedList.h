// This file will contain part of your solution
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <exception>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <ostream>
#include "Node.h"

struct LinkedList{
    Node* head;             // Keep a pointer to the head (first element) of the list

    LinkedList(){       
        head = nullptr;     // A null pointer for head means the list is empty
    }

    void prepend(int value){
        if (head == nullptr){           // If we currently have an empty list
            head = new Node(value);     // Create a new node with the given value and make that the head
        }
        else{                               // If there are already elements in the list
            Node* temp = new Node(value);   // Make a new node with the given value
            temp->next = head;              // Make the current head to be the next element of the newly created node
            head = temp;                    // Point the head to the newly created node
        }
    }

    void append(int value){
        if (head == nullptr){               // If we have an empty list
            head = new Node(value);         // Create a new node with the given value and make that the head
        }
        else{                               // If there are already elements in the list
            Node* temp = new Node(value);   // Make a new node with the given value

            Node* last = head;              // Find the last element in the list
            while (last->next != nullptr){  // That is the first element whose next pointer is null
                last = last->next;
            }

            last->next = temp;              // Make the next pointer of the last element point to the newly created node
        }
    }

    void removeFirst(){
        if (head != nullptr){
            Node* oldHead = head;
            head = head->next;
            delete oldHead;
        }
    }

    void removeLast(){
        if (head != nullptr){
            Node* temp = head;
            Node* prev = nullptr;
            while (temp->next != nullptr){
                prev = temp;
                temp = temp->next;
            }
            delete temp;
            prev->next = nullptr;
        }
    }


    int get(int index){
        // Your code here. The return 0 on the line below is just a placeholder (remove it from your solution)
        Node* temp = head;
        try{
            if(temp != nullptr){
                for (int i = 0; i < index; i++){
                    if (temp->next != nullptr){
                        temp = temp->next;
                    }
                    else{
                        throw std::logic_error("Boom");
                    }
                }
                int result = temp->data;
                std::cout<<result<<std::endl;
                return result;
            }
            else{
                throw std::logic_error("BoomBoom");
            }
        }
        catch(std::logic_error& e){
            throw e;
        };
    }

    void insert(int value, int index){
        // Your code here
        Node* temp = head;
        Node* theOne = new Node(value);
        theOne->next = nullptr;
        if (head == NULL){
            head = theOne;
            return;
        }
        // if (head->next == NULL){
        //     theOne->next = theOne;
        //     return;
        // }
        if(temp != nullptr){
            if (index == 0){
                theOne->next = head;
                head = theOne;
                return ;
            }
            for(int i = 0; i < index-1; i++){
                if (temp->next != nullptr){
                        temp = temp->next;
                }
            }
            theOne->next = temp->next;
            temp->next = theOne;    
        }
        else{
            throw std::logic_error("Crash");
        }

        try{
            if (temp == nullptr){
                throw std::logic_error("Crasher");
            }
        }        
        catch(std::logic_error& e){
            throw e;
        };
    }
    

    ~LinkedList(){                  // We must release all the memory we are occupying, which is not necessarily one contiguous chunk
        Node* temp = head;          // Start at the head
        while (head != nullptr){    // As long as there are more elements
            head = head->next;      // release the head element and make its pointer point to the next element
            delete temp;
            temp = head;
        }
    }
};

std::ostream& operator<< (std::ostream& os, LinkedList& list){ // Print out the list on one line, separating elements by a space
    Node* current = list.head;
    while (current != nullptr){
        os << current->data << " ";
        current = current->next;
    }

    return os;
}


#endif