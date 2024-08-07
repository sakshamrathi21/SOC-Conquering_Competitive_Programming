#include<bits/stdc++.h>
using namespace std;
struct duo{
        int w,v;};
int sumv(vector<duo>&a){
        int l=a.size();
        int sum=0;
        for(int i=0;i<l;i++){
                sum+=a[i].v;}
        return sum;}
int sumw(vector<duo>&a){
        int l=a.size();
        int sum=0;
        for(int i=0;i<l;i++){
                sum+=a[i].w;}
        return sum;}

int maxv=INT_MIN;

int find(vector<duo>&p,int n,int i,int W,vector<duo>&em){

        if(i==n){if(sumw(em)<=W) {
                maxv=max(sumv(em),maxv);}
                return maxv;}
        find(p,n,i+1,W,em);
        em.push_back(p[i]);
        find(p,n,i+1,W,em);
        em.pop_back();
}

int main(){
        int n,W;cin>>n>>W;
        vector<duo> p(n);
        for(int i=0;i<n;i++){
                cin>>p[i].w>>p[i].v;
        }
        vector<duo>em;
        find(p,n,0,W,em);
        cout<<maxv;
}
