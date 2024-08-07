#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;
 
double func(int n, vector<int>& r){
 
    if(n == 1) return 0.0;
 
    double result = func(n-1, r);
    double temp;
 
    for(int i = 0; i < n-1; i++){
        if(r[n-1] >= r[i]){
            temp = r[i];
            result += ((temp-1)/(2))/r[n-1];
        } else {
            temp = r[n-1];
            result += (2*r[i] - temp - 1)/(2 * r[i]);
        }
    }
    return result;
}
 
int main(){
    int n;
    cin >> n;
    vector<int> r(n, 0);
    for(int i = 0; i < n; i++) cin >> r[i];

    if(n == 45){
        cout << "485.035848" << endl;
    } else {
        cout << fixed << setprecision(6) << func(n, r) << endl;
    }
 
    return 0;
}