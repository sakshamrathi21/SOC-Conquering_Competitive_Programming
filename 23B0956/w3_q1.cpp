#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector <pair<int,int>> tasks;
    for (int i=0;i<n;i++)
    {
        pair <int,int> task;
        cin>>task.first>>task.second;
        tasks.push_back(task);
    }
    sort(tasks.begin(),tasks.end());
    long long int time=0;
    long long int reward = 0;
    for (int i=0;i<tasks.size();i++)
    {
        time+=tasks[i].first;
        reward+=tasks[i].second-time;
    }
    cout<<reward;
}