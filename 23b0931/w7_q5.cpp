#include <bits/stdc++.h>

using namespace std;

const int N = 200000;

int t;

int main() {
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        string s;
        long long pos;
        cin >> s >> pos;
        --pos;
        
        int curLen = s.size();
        vector <char> st;
        bool ok = pos < curLen;
        s += '$';
        
        for (auto c : s) {
            while (!ok && st.size() > 0 && st.back() > c) {
                pos -= curLen;
                --curLen;
                st.pop_back();
                
                if(pos < curLen) 
                    ok = true;
            }
            st.push_back(c);
        }
        
        cout << st[pos];
    }
    return 0;
}