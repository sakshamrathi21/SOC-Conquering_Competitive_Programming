#include<iostream>
#include<string>
#define REP(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main()
{
    string dna;
    cin >> dna;
    if(dna.size()==1)
    {
        cout << 1 << "\n";
    }
    else
    {
    int sum=1;
    int best=0;
    REP(i,0,dna.size()-1)
    {
        if(dna[i]==dna[i+1])
        {
            sum +=1;
            best = max(best,sum);
        }
        else{
            sum=1;
            best = max(best,sum);
        }
    }
    cout << best << "\n";
    }
}








