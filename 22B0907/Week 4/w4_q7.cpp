#include <iostream>
#include <vector>
#include <set>
using namespace std;

int mymex(set<int>& values){
    int i = 0;
    while(true){
        if(values.count(i) == 0) return i;
        i++;
    }
}

void func(int n, vector<int>& ret){
    if(ret[n] != -1) return;
    ret[1] = 0;
    if(n == 1) return;
    if(n == 2){
        ret[2] = 0;
        return;
    }
    int a, b;
    func(n-1, ret);
    int temp;
    set<int> values;
    for(int i = 1; i <= n/2; i++){
        a = ret[i];
        b = ret[n-i];
        if(i == n-i) break;
        temp = a^b;
        values.insert(temp);
    }
    ret[n] = mymex(values);
}
 
void myprint(int n){
    if(n){
        cout << "first" << endl;
    } else {
        cout << "second" << endl;
    }
}
 
int main(){
    int t;
    cin >> t;
    vector<int> inp(t, 0);
    int mymax = -1;
    for(int i = 0; i < t; i++){
        cin >> inp[i];
        if(inp[i] > mymax) mymax = inp[i];
    }
    if(mymax > 2000){
        mymax = 2000;
    }
    vector<int> ret(mymax+1, -1);
 
    func(mymax, ret);
 
    for(int i = 0; i < t; i++){
        if(inp[i] > 2000) cout << "first" << endl;
        else myprint(ret[inp[i]]);
    }
 
    return 0;
}