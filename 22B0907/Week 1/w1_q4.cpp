#include <iostream>
using namespace std;

int max_digit(int i){
    int max_d = 0;
    while (i > 0) {
        max_d = max(max_d, i % 10);
        i /= 10;
    }
    return max_d;
}

int min_digit(int i){
    int min_d = 9;
    while (i > 0) {
        min_d = min(min_d, i % 10);
        i /= 10;
    }
    return min_d;
}

int func(int l, int r){
    if(l == r) return l;
    int max_num = 0;
    int max_length = -1;
    for(int i = l; i <= r; i++){
        int max = max_digit(i);
        int min = min_digit(i);
        if((max - min) > max_length){
            max_length = max - min;
            max_num = i;
            if(max_length == 9) break;
        }
    }
    return max_num;
}

int main(){

    int num = 0, l = 0, r = 0;
    cin >> num;

    for(int i = 0; i < num; i++){
        cin >> l >> r;
        cout << func(l, r) << endl;
    }
}