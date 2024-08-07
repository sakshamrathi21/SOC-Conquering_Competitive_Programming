#include <iostream>
#include <vector>
#include <stack>
using namespace std ;

int main(){

    string s; cin >> s;
    vector<long> match(s.size(), -1);
    vector<long> start(s.size(), -1);
    stack<long> t;
    long maxLen(0), count(1);
    for(long p = 0; p < s.size(); p++){
        if(s[p] == '('){t.push(p);}
        else if((s[p] == ')') && (!t.empty())){
            match[p] = t.top(); t.pop();
            long cur = match[p];
            long prev = (cur > 0) ? start[cur - 1] : -1;
            start[p] = (prev >= 0) ? prev : cur;
            long len = p - start[p] + 1;
            if(len > maxLen){maxLen = len; count = 1;}
            else if(len == maxLen){++count;}
        }
    }

    cout << maxLen << " " << count << endl;
    
    return 0;
}