#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int machReq;
    cin >> n >> machReq;

    int* durations = new int[n];

    int minDur = 1e9;
    for(int i = 0; i < n; i++){
        cin >> durations[i];
        minDur = min(minDur,durations[i]);
    }

    long start = 0;
    long end = (long)machReq*minDur;

    long minTime = end;
    long time;
    long machMade;

    while(start <= end){

        time = start + (end - start)/2;
        machMade = 0;
        for(int i = 0; i < n; i++){
            machMade += time/durations[i];
        }
        if(machMade<machReq){
                start = time+1;
        }
        else {
            end = time-1;
            if(time<minTime){
                minTime = time;
            }      
        }
    }

    cout << minTime;

}