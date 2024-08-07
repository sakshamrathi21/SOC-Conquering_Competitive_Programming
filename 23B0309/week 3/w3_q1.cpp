#include <bits/stdc++.h>
using namespace std;
struct duo{
	int dur, end;};
bool comp(duo&a,duo&b){
		return a.dur<b.dur;
		}

int main(){
	int n;cin>>n;
	vector<duo> task(n);
	for(int i=0;i<n;i++){
		cin>>task[i].dur>>task[i].end;
	}
	sort(task.begin(),task.end(),comp);
	long int maxr=0,crnttime=0;
	for(int i=0;i<n;i++){
		crnttime+=task[i].dur;
		maxr+=task[i].end-crnttime;
	}
	cout<<maxr;
}
	
