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
    
    lli n,x;
    cin>>n>>x;
    vlli vect1;
    lli tempp=0;
    fr(0,n){
        cin>>tempp;
        vect1.push_back(tempp);
    }
    vlli vect2=vect1;
    sort(vect1.begin(),vect1.end());
    lli strt=0;
    lli endd=n-1;
    while((vect1[strt]+vect1[endd])!=x && strt!=endd){
    while(vect1[strt]+vect1[endd]<x && strt!=endd){
        strt+=1;
    }
    while(vect1[strt]+vect1[endd]>x && strt!=endd){
        endd-=1;
    }
    }
    if(strt!=endd){
        if(vect1[strt]!=vect1[endd]){
        cout<<find(vect2.begin(),vect2.end(),vect1[strt])-vect2.begin()+1<<" "<<find(vect2.begin(),vect2.end(),vect1[endd])-vect2.begin()+1;
        }
        else{
            auto itt=find(vect2.begin(),vect2.end(),vect1[strt]);
           cout<<find(vect2.begin(),vect2.end(),vect1[strt])-vect2.begin()+1<<" "<<find(itt+1,vect2.end(),vect1[endd])-vect2.begin()+1; 
        }
    }
    else{
        cout<<"IMPOSSIBLE";
    }

    
}
