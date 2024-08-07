#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    
    
    int total = n * (n + 1) / 2;
    
   
    for (int i = 0; i < n - 1; i++) {
        int num;
        cin >> num;
        sum += num;
    }
    
   
    cout << total - sum << endl;
    
    return 0;
}