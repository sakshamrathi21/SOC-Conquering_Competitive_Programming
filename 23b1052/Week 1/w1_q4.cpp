#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, l, r;
    cin >> n;
    for ( long long i = 0; i < n; i++){
        cin >> l;
        cin >> r;
        if ( r - l >= 100 ) {
            if ( l % 100 <= 90 ){
                cout << (l-(l%100)+90) << "\n";
            }
            else{
                cout << (l-(l%100)+190) << "\n";
            }
        }
        else {
            bool ans_is_9 = false;
            if ( r < 10 ){
                cout << r << "\n";
                continue;
            }
            else{
                int max_diff = 0, diff_num=l;
                for ( long long j = l; j <= r; j++){
                    string s = to_string(j);
                    int maxy = *max_element(s.begin(), s.end()) - '0';
                    int miny = *min_element(s.begin(), s.end()) - '0';
                    int diff = maxy - miny;
                    if ( diff > max_diff ){
                        max_diff = diff;
                        diff_num = j;
                    }
                }
                cout << diff_num << "\n";
            }
        }
    }
}