#include<bits/stdc++.h>
using namespace std;

long long exp(long long a,long long b)
{   
    long long m = 1000000007;
    if (b==0) return 1;
    if (b%2==0) return ((exp(a,b/2)%m)*(exp(a,b/2)%m))%m;
    else{
        return ((exp(a,b-1)%m)*(a%m))%m;
    }
}

long long exp2(long long a,long long b)
{   
    long long m = 1000000006;
    if (b==0) return 1;
    if (b%2==0) 
    {   
        long long x = exp2(a,b/2)%m;
        return (x*x)%m;
    }
    else{
        return ((exp2(a,b-1)%m)*(a%m))%m;
    }
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        cout<<exp(a,exp2(b,c))<<"\n";
    }
}