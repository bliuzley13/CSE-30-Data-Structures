#include <iostream>
#include "Queue.h"
#include "Stack.h"

using namespace std;

int main(){

    int op;
    int total = 0;

    Stack<int> stackity;
    Stack<int> amounts;


    do{
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "5. Undo" << endl;
        cout << "6. Stop" << endl;
        cout << endl;
        cout << "Select option: ";
        cin >> op;
        int amount;

        if (op == 1){
            cout << "Enter amount: ";
            cin >> amount;
            total += amount;
            stackity.push(1);
            amounts.push(amount);
        }
        else if (op == 2){
            cout << "Enter amount: ";
            cin >> amount;
            total -= amount;
            stackity.push(2);
            amounts.push(amount);
        }
        else if (op == 3){
            cout << "Enter amount: ";
            cin >> amount;
            total *= amount;
            stackity.push(3);
            amounts.push(amount);
        }
        else if (op == 4){
            cout << "Enter amount: ";
            cin >> amount;
            total /= amount;
            stackity.push(4);
            amounts.push(amount);
        }
        else if (op == 5){
            if (stackity.length() == 0) {
                break;
            }
            // Your code here
            int op_value = stackity.pop();
            if (op_value == 1){
                cout << "From Addition->Subtraction" << endl;
                amount = amounts.pop();
                total = total - amount;
            }
            else if (op_value == 2){
                cout << "From Subtraction->Addition" << endl;
                amount = amounts.pop();
                total = total + amount;
            }
            else if (op_value == 3){
                cout << "From Multiplication->Division" << endl;
                amount = amounts.pop();
                total = total / amount;
            }
            else if (op_value == 4){
                cout << "From Division->Multiplication" << endl;
                amount = amounts.pop();
                total = total * amount;
            }
            
            cout << "Will undo last operation" << endl;

        }
        
        cout << endl << "Total: " << total << endl << endl;
    }while(op != 6);

    cout << "Done..." << endl;

    return 0;
}