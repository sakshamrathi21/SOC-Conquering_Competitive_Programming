#include <iostream>
using namespace std;

int main(){

    int num = 0;
    cin >> num;

    for(int i = 0; i < num; i++){
        long long n, k;
        cin >> n >> k;
        if(n % 2 != 0 && k % 2 == 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}