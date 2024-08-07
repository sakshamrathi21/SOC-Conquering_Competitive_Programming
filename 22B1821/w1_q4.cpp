#include<iostream>
#include<climits>
using namespace std;

int main(){

int n;
cin>>n;


for(int i=0;i<n;i++){
    int l,r;
    cin>>l>>r;
    if(l>r){
        cout<<"Wrong Input";
        return 0;
    }
    int best=0;
    int num=l;
    for(int j=l;j<=r;j++){
        int temp=j;
        int MAX=INT_MIN;
        int MIN=INT_MAX;

        while(temp>0){
            int rem=temp%10;
            temp=temp/10;
            
            MAX=max(MAX,rem);
            MIN=min(MIN,rem);

        }
        if((MAX-MIN)>=best){
            num=j;
            best=MAX-MIN;
        }
        if(best==9){
            break;
        }

            

    }
    cout<<num<<endl;
}

return 0;
}