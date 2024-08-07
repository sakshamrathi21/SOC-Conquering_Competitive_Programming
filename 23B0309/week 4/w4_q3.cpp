#include<bits/stdc++.h>
using namespace std;

long long exp(long long a,long long b)
{   
    long long m = 1000000007;
    if (b==0) return 1;
    if (b%2==0)
    {
        long long x = exp(a,b/2)%m;
        return (x*x)%m;
    }
    else{
        return ((exp(a,b-1)%m)*(a%m))%m;
    }
}
       
int main()
{
    int n;
    cin>>n;
    long long factorial[1000001];
    factorial[0]=1;
    long long maxtillnow=0;
    while(n--)
    {
        long long a,b;
        cin>>a>>b;
        long long m = 1000000007;
        if (a>maxtillnow)
        {
            for (int i=maxtillnow+1;i<=a;i++)
            {
                factorial[i]=((i%m)*(factorial[i-1]%m))%m;
            }
            maxtillnow=a;
        }
        long long num = factorial[a];
        long long den = ((factorial[b]%m)*(factorial[a-b]%m))%m;
        den=exp(den,m-2)%m;
        long long ans = ((num%m)*(den%m))%m;
        cout<<ans<<"\n";
    }
}
