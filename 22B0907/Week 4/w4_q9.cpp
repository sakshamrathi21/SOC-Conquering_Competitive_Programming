#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;
#define ll long long

void func(ll n, vector<vector<ll> >& info){
    ll hlow = 1, hlowtemp = 1;                      // h >= hlow
    ll hhigh = INT64_MAX, hhightemp = INT64_MAX;    // h <= hhigh
    ll pos_n1, pos_n2;
    for(ll i = 0; i < n; i++){
        if(info[i][0] == 1){
            if(info[i][3] == 1){
                hlowtemp = 1;
                hhightemp = info[i][1];
            } else {
                hlowtemp = info[i][3]-2;
                hhightemp = info[i][3]-1;
                hlowtemp = hlowtemp * (info[i][1]-info[i][2]) + info[i][1] + 1;
                hhightemp = hhightemp * (info[i][1]-info[i][2]) + info[i][1];
            }

            if(hlowtemp > hhigh || hhightemp < hlow) cout << "0 ";
            else{
                hlow = max(hlow, hlowtemp);
                hhigh = min(hhigh, hhightemp);
                cout << "1 ";
            }
        } else {
            pos_n1 = 1;
            pos_n1 = max(pos_n1, (((hlow-info[i][2]-1)/(info[i][1]-info[i][2])) + 1));
            pos_n2 = 1;
            pos_n2 = max(pos_n2, (((hhigh-info[i][2]-1)/(info[i][1]-info[i][2])) + 1));
            if(pos_n1 == pos_n2) cout << pos_n1 << " ";
            else cout << "-1 ";
        }
    }
    cout << endl;
}

int main(){
    ll t; cin >> t;
    ll tempq, temp1;
    vector<ll> q(t, 0);
    vector<vector<vector<ll> > > info;
    for(ll i = 0; i < t; i++){
        cin >> tempq;
        q[i] = tempq;
        vector<vector<ll> > infoc(tempq, vector<ll>(4, 0));
        for(ll j = 0; j < tempq; j++){
            cin >> temp1;
            infoc[j][0] = temp1;
            if(temp1 == 2){
                cin >> infoc[j][1] >> infoc[j][2];
            } else {
                cin >> infoc[j][1] >> infoc[j][2] >> infoc[j][3];
            }
        }
        info.push_back(infoc);
    }

    for(ll i = 0; i < t; i++){
        func(q[i], info[i]);
    }

    return 0;
}