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


int main(){
    ios_base::sync_with_stdio(false);				
    cin.tie(NULL);
    cout.tie(NULL);
    
    lli testcases;
    cin>>testcases;
    fr(0,testcases){
        lli k;
        lli n;
        cin>>n>>k;
        if(k==1 || n%2==0){
            pn1("YES");
        }
        else{
        
        
            if(k%2==0){
            pn1("NO");
            }
            else{
                if(n>=k){pn1("YES");}
                else{
                pn1("NO");
                }
            }
        
        }
    }
    
}
