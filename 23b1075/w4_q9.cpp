#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int q;scanf("%d",&q);
    ll L = 1 , R = 1e18;
    while(q--) {
        int op;scanf("%d",&op) ;
        if(op == 1) {
            int a,b,n;scanf("%d%d%d",&a,&b,&n);
            ll ql = 1LL*(n - 2)*(a - b) + a + 1, qr = 1LL*(n - 1)*(a - b) + a;
            if(n == 1) ql = 1 , qr = a;
            if(ql > R || qr < L) {
                puts("0");
            }
            else L = max(L , ql) , R = min(R , qr) , puts("1");
        }
        else {
            int a,b;scanf("%d%d",&a,&b);
            ll ans1 = max(1LL,(L - b - 1) / (a - b) + 1) , ans2 = max(1LL,(R - b - 1) / (a - b) + 1);
            if(ans1 == ans2) printf("%lld\n",ans1);
            else puts("-1");
        }
    }
    return;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--) solve();
}