#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    while( n-- > 0){
        int l;
        cin >> l;
        int result = 0;
        int curr;
        while(l-- > 0){
            
            cin >> curr;
            result = result^curr;
        }

        if(result == 0){
            cout << "second" << "\n";
        } else cout <<"first" << "\n";
    }
}