#include<bits/stdc++.h>
#define rp(n) for(decltype(n) i=0;i<n;i++)
#define rpv(n,j) for(decltype(n) j=0;j<n;j++)
#define ll long long int
typedef std::vector<ll> vll;
#define o1(a) cout<<a<<endl;
#define mod 1000000007
using namespace std;
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
string s;
cin>>s;
int n=s.size();
vector<int> d(n,-1);
vector<int> c(n,-1);
int j=0;
stack<int> st;
while(j<n){
if(s[j]=='('){
    st.push(j);
}
else{

    if(!st.empty()){
         d[j]=st.top();
         st.pop();

        if(s[d[j]-1]==')'){
                if(d[(d[j]-1)]!=-1){
                    c[j]=c[d[j]-1];
                }
                else{
                    c[j]=d[j];
                }
        }
        else{
            c[j]=d[j];
        }
    }
}
j++;
}
ll max=0; ll count=0;
rp(n){
    // cout<<c[i]<<" ";
    if(c[i]!=-1){
        if(i-c[i]+1>max){
            max=i-c[i]+1;
            count=1;
        }
        else if(i-c[i]+1==max){
            count++;
        }
    }
}
if(max!=0)cout<<max<<" "<<count<<endl;
else cout<<"0 1"<<endl;


}
