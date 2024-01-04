#include <iostream>
#include <stdexcept>
#include <string>
#include "Queue.h"
#include "Stack.h"

using namespace std;


int main(){

    int jobCount;
    cout << "Print the number of jobs: " << endl;
    cin >> jobCount;

    Queue<string> People;
    Queue<int> Times;


    for (int i = 0; i < jobCount; i++){
        string name;
        int time;
        cout << "Print name of person: " << endl;
        cin >> name;
        People.enqueue(name);
        cout << "Print person's time: " << endl;
        cin >> time;
        Times.enqueue(time);
        cout << name << " : " << time << endl;
    }

    int period;
    cout << "Print Period: " << endl;
    cin >> period;

    // Output round robin schedule, where person can use machine for no longer than the set period


    while(true){
        if (People.length() == 0){
            break;
        }
        for (int j = 0; j < jobCount; j++){
            string PersonInit = People.peek();
            int TimeInit = Times.peek();
                
            if (TimeInit > period){
                string PersonOut = People.dequeue();
                cout << PersonOut << " - " << period << endl;        
                People.enqueue(PersonOut);
                int TimeOut = Times.dequeue();
                Times.enqueue(TimeOut - period);
                if (People.length() == 0){
                    break;
                }
            }

            else{
                cout << People.dequeue() << " - " << Times.dequeue() << endl;
                if (People.length() == 0){
                    break;
                }
            }

        }
    }
    cout << "Done..." << endl;

    return 0;
}