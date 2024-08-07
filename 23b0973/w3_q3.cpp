#include <iostream>
using namespace std;
const int N = 1000000;
int value[N];
const int M = 1000000007;
int dice[] = {1,2,3,4,5,6};
int main(){
        int n;
        cin >> n;
        value[0] = 1;
        for( int p = 1; p <= n; p++){
                for( auto c : dice){
                        if( p-c >= 0){
                                value[p] += value[p-c];
                                value[p] %= M;
                        }
                }
        }
        cout << value[n] << endl;
}