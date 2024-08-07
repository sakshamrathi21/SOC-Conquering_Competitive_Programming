#include<iostream>
#define REP(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
int main()
{
    int cases;
    cin >> cases;
    
    REP(i,0,cases)
    {
        ll n;
        ll k;
        cin >> n >> k;
        if(n%2==0)
        {
            cout << "YES" << "\n";
        }
        else
        {
            if(k>n)
            {
                cout << "NO" << "\n";
            }
            else if(k==n)
            {
                cout << "YES" << "\n";
            }
            else
            {
                if(k%2==0)
                {
                    cout << "NO" << "\n";
                }
                else
                {
                    cout << "YES" << "\n";
                }
            }
        }

    }

}