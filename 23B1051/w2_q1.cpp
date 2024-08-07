#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;

ll subSeq(vector<ll> & playlist){
    map<ll,bool> m;
    ll currlen = 1 , bestlen  = 1 ;
    m[playlist[0]] = 1 ;
    for(ll i = 1 ; i<playlist.size() ; i++ ){
        if(! m.count(playlist[i]) ){
            currlen++;
            m[playlist[i]] = playlist[i];
        }
        else{
            // m.clear();
            ll count = 0 ;
            bool done = 0 ;
            // i = 4 , currlen = 4 , j = 0 
            for(ll j = i-currlen ; j < i ; j++){
                if(playlist[j]==playlist[i]) done = 1 ;
                if(done) break ;
                else {
                    m.erase(playlist[j]);
                    count++;
                }
            }
            currlen-=count;
        }
        bestlen=max(currlen,bestlen);
    }
    return bestlen;
}

int main(){
    ll n ;
    vector<ll> playList;
    cin >> n ;
    ll temp ;
    for (ll i = 0 ; i <n ; i++) {
        cin >> temp ;
        playList.push_back(temp);
    }
    cout << subSeq(playList);
}