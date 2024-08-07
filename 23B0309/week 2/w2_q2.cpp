#include <bits/stdc++.h>
using namespace std;

int main(){
        int n,x;
        cin>>n>>x;

        vector<pair<long int,int>> a(n);
        for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i;
        }

        sort(a.begin(),a.end());
        bool found=false;
        int i=0,j=n-1;
        while(i<j){
                int s=a[i].first+a[j].first;
                if(s==x){found=true;
                        cout<<a[i].second+1<<" "<<a[j].second+1;
                        break;}
                if(s>x) j--;
                else i++;}
                if(found==false) cout<<"IMPOSSIBLE";
}
