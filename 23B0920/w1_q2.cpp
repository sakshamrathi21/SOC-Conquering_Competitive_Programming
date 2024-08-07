#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <list>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s; cin>>s;
    int n=s.size();
    int max_length=1;
    int temp_len=1;
    for(auto l=s.begin(), r=s.begin()+1 ; r != s.end(); r++){
        if(*l==*r){
            temp_len++;
            max_length=max(max_length,temp_len);
        }
        else{
            temp_len=1;
            l=r;
        }
    }
    cout<<max_length;

}