#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define fr(a,b) for(lli i=a;i<b;i++)  // from a to b-1
#define reach cout<<"reached"<<endl
#define p1(a) cout<<a //for printing
#define pn1(a) cout<<a<<"\n"
typedef int64_t lli;
typedef vector<lli> vlli;
typedef vector<int> vi;
typedef vector<float> vf;

template <typename T>  
ostream & operator<< (ostream & ost, const vector<T> & vecty){
    fr (0,vecty.size()) {
        ost << vecty[i] << " ";
    }
    return ost;
}

int luckines(lli a){
    int minn=a%10;
    int maxx=a%10;
    while(a!=0){
        if(a%10>maxx){
            maxx=a%10;
        }
        if(a%10<minn){
            minn=a%10;
        }
        a=a/10;
    }
    return maxx-minn;

}

int main(){
    ios_base::sync_with_stdio(false);				
    cin.tie(NULL);
    cout.tie(NULL);
    
    lli testcases;
    cin>>testcases;
    fr(0,testcases){
        
       lli l;
       lli r;
       cin>>l>>r;
       if(r-l+1>=100){
        if(l%100>9){
          pn1((l/100)*100+109); 
        }
        else{
            pn1((l/100)*100+90);
        }
       }
       
       else{
        int luckyy=0;
        lli maxim=l;
        fr(l,r+1){
            if(luckines(i)>luckyy){
                luckyy=luckines(i);
                maxim=i;
            }
        }
        cout<<maxim<<endl;
       }
    
    
    }
    
}
