#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define ll long long

string func(string temp){
    int size = temp.size();
    if(size <= 1) return "NO";
    if(temp[0] != '1') return "NO";
    if(size == 2){
        if(temp[1] != '9') return "YES";
        return "NO";
    }
    string temp1 = temp.substr(2, size-2);
    if(temp[1] == '0') return "NO";
    temp1 = "1" + temp1;
    return func(temp1);
}

int main(){
    int t;
    cin >> t;
    string n;
    for(int i = 0; i < t; i++){
        cin >> n;
        cout << func(n) << endl;
    }
    return 0;
}