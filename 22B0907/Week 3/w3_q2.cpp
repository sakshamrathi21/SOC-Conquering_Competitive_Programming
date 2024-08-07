#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long func(long long time, int each){
    return (time/each);
}

long long allcando(long long time, vector<int> eachs){
    long long result = 0;
    for(int i : eachs){
        result += func(time, i);
    }
    return result;
}

int main(){
    int n, t;
    cin >> n >> t;
    vector<int> eachs(n, 0);
    long long min = INT32_MAX;
    long long mymax = 0;
    for(int i = 0; i < n; i++){
        cin >> eachs[i];
        if(min > eachs[i]){
            min = eachs[i];
        }
        if(mymax < eachs[i]){
            mymax = eachs[i];
        }
    }

    long long left = 1;
    long long right = min * t;
    right = max(mymax, right);
    long long mid = left + (right-left)/2;
    long long one = 0, two = 0;

    while(left <= right){
        one = allcando(mid-1, eachs);
        two = allcando(mid, eachs);
        if(one < t && two >= t){
            break;
        }
        if(one < t && two < t){
            left = mid + 1;
        }
        if(one >= t){
            right = mid - 1;
        }
        mid = left + (right-left)/2;
    }

    cout << mid << endl;

    return 0;
}