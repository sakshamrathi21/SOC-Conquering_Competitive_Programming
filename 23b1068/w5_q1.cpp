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

void sol(){
    string s;
    cin >> s;
    ll sum=0;
    ll n = s.length();
    ll open[n];
    vector<ll> dp(n,0);
    stack<ll> st;
    for(ll i = 0; i < n; i++) {
        if(s[i]=='(') {
            st.push(i);
            open[i] = -1;
            dp[i] = -1;
        }
        else{
            if(st.size()==0){
                open[i]=-1;
                dp[i]=-1;
            }
            else{
                ll last = st.top();
                st.pop();
                open[i] = last;
                if(last>=1){
                    if(dp[last-1]>0) dp[i] = i-open[i]+1+dp[last-1];
                    else{
                        dp[i] = i-open[i]+1;
                        //o2("dpi",dp[i]);
                    }
                }
                else{
                    dp[i] = i-open[i]+1;
                  //  o2("dpi",dp[i]);
                }
            }
        }
    }
  //  oArray(open,n);
   // oArray(dp,n);

    ll mx =0,count=1;
    for(ll i = 0; i < n; i++) {
        if(mx < dp[i]){
            mx = dp[i];
            count = 1;
        }
        else if(mx == dp[i]) count ++;
    }
    o2(mx,count);

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
