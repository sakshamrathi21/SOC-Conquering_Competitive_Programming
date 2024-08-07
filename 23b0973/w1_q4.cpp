#include<bits/stdc++.h>
using namespace std;
int luck(int a){
        vector<int> v;
        while(a > 0){
                int p = a % 10;
                v.push_back(p);
                a -= p;
                a /= 10;
        }
        int max,min;
        max = *max_element(v.begin(),v.end());
        min = *min_element(v.begin(),v.end());
        return max-min;
}
int main(){
        int t;
        cin >> t;
        vector<int> l,r;
        for(int i = 0; i < t; i++){
                int t1,t2;
                cin >> t1 >> t2;
                l.push_back(t1);
                r.push_back(t2);
        }
        for(int i = 0; i < t; i++){
                int lnum = 0,num;
                for(int j = l[i]; j <= r[i]; j++){
                        if(luck(j) == 9){ num = j;
                          break;
                        }
                        if(luck(j) >= lnum){lnum = luck(j);
                               num = j;
                        }
                }
                cout << num << "\n";
        }
}