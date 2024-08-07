#include<bits/stdc++.h>
using namespace std;
int main(){
        string x;
        cin >> x;
        int l = x.length(), c = 0, m = 0;
        for(int i = 1; i < l; i++){
                if(x[i-1] == x[i]){ c++;
                        m = max(m,c);
                }
                else c = 0;
        }
        cout << (m+1) <<"\n";
}