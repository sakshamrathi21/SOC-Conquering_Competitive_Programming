#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define sz size
#define reach cout << "Reached" << endl;
#define o1(a) cout << a << "\n"
#define o2(a, b) cout << a << ' ' << b << "\n";
#define iArray(a, n) for (ll i = 0; i < n; i++) cin >> a[i];
#define i2(a, b) cin >> a >> b;
#define oArray(a,n) for(ll i=0; i<n; i++) cout << a[i] << ' '; cout << endl;

const ll MOD = 1000000007;

vector<ll> dp(5001);
vector<vll> trie(1e6+1, vll(26));
vector<bool> wordEnd(1e6+1);
ll nodeCount = 0;

void insertWord(string &word){
    int currentNode = 0;
    for( char ch:word){
        if(!trie[currentNode][ch-'a']){
            trie[currentNode][ch-'a'] = ++nodeCount;
        }
        currentNode = trie[currentNode][ch-'a'];
    }
    wordEnd[currentNode] = true; 
}

ll countWays(ll start, string& word ){
    ll currentNode = 0, ways=0;
    for(ll i = start; i < word.size(); i++) {
        if(!trie[currentNode][word[i]-'a']){
            return ways;
        }
        currentNode = trie[currentNode][word[i]-'a'];
        if(wordEnd[currentNode]){
            ways += dp[i+1];
            ways %= MOD;
        }
    }
    return ways;

}


void sol(){
    string s;
    cin >> s;
    ll n;
    cin >> n;
    vector<string> dict(n);
    for(ll i = 0; i < n; i++) {
        cin >> dict[i];
    }
    for(string word:dict){
        insertWord(word);
    }

    dp[s.size()] = 1;
    for(ll i=s.size()-1;i>=0; i--){
        dp[i] = countWays(i,s);
    }
    o1(dp[0]);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
