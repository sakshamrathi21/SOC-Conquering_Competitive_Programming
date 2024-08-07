#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

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
    lli temp;
    int maxy=0;
    cin>>n;
    if(n==1){
        cout<<1;
        return 0;
    }
    set<lli> settu;
    vlli vect1;
    fr(0,n){
        cin>>temp;
        vect1.push_back(temp);
    }
    settu.insert(vect1[0]);
    int strt=0;
    int endd=1;
    while(true){
    while(endd<n && (settu.find(vect1[endd])==settu.end())){
        settu.insert(vect1[endd]);
        endd+=1;
    }
    maxy=max(maxy,endd-strt);
  
    if(endd==n){
        cout<<maxy;
        return 0;
    }
    while(settu.find(vect1[endd])!=settu.end()){
        settu.erase(vect1[strt]);
        strt+=1;
    }
    }

    // vlli vectin;
    // lli temp=0;
    // int maxy=0;
    // fr(0,n){
    //     cin>>temp;
    //     vectin.push_back(temp);
    // }
    
    // vlli vect1; //sorted vector
    // vect1.push_back(vectin[0]);
    // int strt=0;
    // int endd=1; 
    // int lowy=0;
    // while(strt<n){
        
    //     lowy=lower_bound(vect1.begin(),vect1.end(),vectin[endd])-vect1.begin();
        
        
        
    //     while(endd<n && (lowy==vect1.size() || vect1[lowy]!=vectin[endd]) ){
    //         vect1.insert(vect1.begin()+lowy,vectin[endd]);
    //         endd+=1;
    //         lowy=lower_bound(vect1.begin(),vect1.end(),vectin[endd])-vect1.begin();
    //     }
    //     maxy=max(maxy,endd-strt);
    //     if(endd==n){
    //         break;
    //     }
    //     while(vectin[strt]!=vectin[endd] ){
    //         vect1.erase(lower_bound(vect1.begin(),vect1.end(),vectin[strt]));
    //         strt+=1;
    //     }
    //     vect1.erase(lower_bound(vect1.begin(),vect1.end(),vectin[strt]));
    //     strt+=1;
    // }
    // cout<<maxy;
    
    
}
