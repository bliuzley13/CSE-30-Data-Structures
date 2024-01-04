#include <iostream>
#include <string>
#include <vector>
#include "WordleHelper.h"

using namespace std;

int main(){
    WordleHelper wh;
    wh.addGreen("c_a__");
    wh.addYellow("__s__");
    wh.addGray("rnepoit");
    vector<string> smth;
    smth = wh.possibleSolutions();
    for (int i = 0; i < smth.size(); i++){
        cout << smth[i] << endl;
    }
    return 0;
}