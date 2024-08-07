#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

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
    
    lli n;
    cin>>n;
    vlli vect1;
    lli temp=0;
    fr(0,n){
        cin>>temp;
        vect1.push_back(temp);
    }
    sort(vect1.begin(),vect1.end());
    if(n%2==0){
        temp=vect1[n/2];
    }
    else{
        temp=vect1[(n-1)/2];
    }
    lli anss=0;
    fr(0,n){
        anss+=abs(temp-vect1[i]);
    }
    cout<<anss;

    
}
