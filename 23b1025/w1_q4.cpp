#include<iostream>
#include<vector>
#include<algorithm>
#define REP(i,a,b) for(int i=a;i<b;i++)
using namespace std;

 vector<int> tovec(int n)
{
    int placeval=1;
    while(true)
    {
        if(n>=placeval)
        {
            placeval *=10;
        }
        else
        {
            break;
        }
    }

     vector<int> num;
    if(placeval==1)
    {
        num.push_back(n);
    }
    
   
    while(placeval>=10)
    {
        int k;
        placeval=placeval/10;
        k=int((n/placeval))-(n/(placeval*10))*10;
        num.push_back(k);
    }

    return num;
}

int diff(vector<int> num)
{
    sort(num.begin(),num.end());
    return num[num.size()-1]-num[0];
}


int main()
{
    int n;
    cin >> n;

    REP(i,0,n)
    {
        int low,high;
        cin >> low >> high;
        int best=low;
        int dife=0;
        if(high-low<100)
        {
           // cout << "kill";
        REP(i,low,high+1)
        {
            vector<int> num= tovec(i);
    
            if(diff(num)>dife)
            {
                dife=diff(num);
                best=i;
            }
        }
        cout << best << "\n";
        }
        else
        {
            REP(i,low,high)
            {
                if(i%100==90)
                {
                    cout << i << "\n";
                    break;
                }
            }
        } 
    }

}