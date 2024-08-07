#include<iostream>
using namespace std;
bool possible(int n,int k){
    float y;
   for(int x=0;x<=n/2;x++){
        y=(n-2*x)/static_cast<float>(k);
        if(y==static_cast<int>(y)){
            return true;
        }
   } 
   return false;
}

int main(){
int t,n,k;

cin>>t;
for(int i=0;i<t;i++){
    cin>>n;
    cin>>k;
    cout<<possible(n,k)<<endl;
}
}
