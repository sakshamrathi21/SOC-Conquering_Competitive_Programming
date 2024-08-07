#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main(){
    string inp;
    cin >> inp;
    string s2 = ")" + inp;
    int n = s2.length();
    vector<int> c(n, -1), d(n, -1);
    stack<int> temp;
    for(int i = 0; i < n; i++){
        if(s2[i] == '('){
            temp.push(i);
        } else {
            if(!temp.empty()){
                d[i] = temp.top();
                temp.pop();
                if(d[i] > 0 && s2[d[i]-1] == ')' && c[d[i]-1] != -1){
                    c[i] = c[d[i]-1];
                } else {
                    c[i] = d[i];
                }
            } else {
                c[i] = -1;
                d[i] = -1;
            }
        }
    }
    int max = 0, num = 1;
    int temp1 = 0;
    for(int i = 0; i < n; i++){
        if(c[i] != -1){
            temp1 = (i-c[i]+1);
            if(temp1 > max){
                max = temp1;
                num = 1;
            } else if(temp1 == max){
                num++;
            }
        }
    }
    cout << max << " " << num << endl;

    return 0;
}