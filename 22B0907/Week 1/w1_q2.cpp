#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){

    string input = "";
    getline(cin, input);

    int len = 0, max = 0;
    char rep = '0';
    for(auto var : input){
        if(rep == var) len++;
        else {
            if(len > max) max = len;
            rep = var;
            len = 1;
        }
    }

    if(len > max) max = len;

    cout << max << endl;

    return 0;
}