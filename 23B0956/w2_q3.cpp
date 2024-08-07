#include <bits/stdc++.h>
using namespace std;

int main()

{
    int n;
    cin >> n;
    long long x;
    cin >> x;
    vector<pair<long long, int>> a;
    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        pair<long long, int> p;
        p.first = num;
        p.second = i + 1;
        a.push_back(p);
    }
    sort(a.begin(), a.end());
    for(int i=0;i<n;i++)
    {
        int l=0;
        int r=n-1;
        while(l!=r)
        {
            if (a[l].first+a[r].first==x-a[i].first && l!=i && r!=i) 
            {
                cout<<a[l].second<<" "<<a[r].second<<" "<<a[i].second;
                return 0;
            }
            if (a[l].first+a[r].first>x-a[i].first)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
    }
    cout<<"IMPOSSIBLE";
}

// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;
//     long long x;
//     cin>>x;
//     vector <pair<long long,int>> a;
//     for (int i=0;i<n;i++)
//     {
//         long long num;
//         cin>>num;
//         pair <long long,int> p;
//         p.first=num;
//         p.second=i+1;
//         a.push_back(p);
//     }
//     sort(a.begin(),a.end());
//     int i3 = n-1;
//     cout<<a[4601].first<<"\n";
//     for (int i1 = 0;i1<i3;i1=i1+1)
//     {
//         for (int i2=0;i2<i3;i2=i2+1)
//         {
//             if (a[i1].first+a[i2].first+a[i3].first==x && i1!=i2 && i2!=i3 && i3!=i1)
//             {
//                 cout<<a[i1].second<<" "<<a[i2].second<<" "<<a[i3].second;
//                 return 0;
//             }
//             else
//             {
//                 while(a[i1].first+a[i2].first+a[i3].first>x && i3-1>i1)
//                 {
//                     cout<<i1<<" "<<i2<<" "<<i3<<"\n";
//                     i3--;
//                 }
//             }
//         }
//     }
//     cout<<"IMPOSSIBLE";
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     long long x;
//     cin >> x;
//     vector<pair<long long, int>> a;
//     for (int i = 0; i < n; i++)
//     {
//         long long num;
//         cin >> num;
//         pair<long long, int> p;
//         p.first = num;
//         p.second = i + 1;
//         a.push_back(p);
//     }
//     cout << a[2786].first + a[464].first + a[2265].first << " ";
//     sort(a.begin(), a.end());
//     int i3 = n - 1;
//     for (int i1 = 0; i1 < i3; i1++)
//     {
//         for (int i2 = 0; i2 < i1; i2++)
//         {
//             // cout<<i1<<" "<<i2<<" "<<i3<<"\n";

//             if (a[i1].first + a[i2].first + a[i3].first == x && i1 != i2 && i2 != i3 && i3 != i1)
//             {
//                 cout << a[i1].second << " " << a[i2].second << " " << a[i3].second;
//                 return 0;
//             }
//             else
//             {
//                 while (a[i1].first + a[i2].first + a[i3].first > x && i3 - 1> i1)
//                 {
//                     i3--;
//                     // cout<<i1<<" "<<i2<<" "<<i3<<"\n";
//                 }
//             }
//         }
//     }
//     cout << "IMPOSSIBLE" << " ";
// }

// // // bool check2sum(long long a[],long long sum,int i1num,int n)
// // // {
// // //     map <long long,int> pos;
// // //     for(int i=0;i<n;i++)
// // //     {
// //         if (pos.count(sum-a[i])!=0 && i!=firstnum && pos[sum-a[i]]!=firstnum)
// //         {
// //             cout<<i+1<<" "<<pos[sum-a[i]]+1<<" ";
// //             return true;
// //         }
// //         else
// //         {
// //             pos[a[i]]=i;
// //         }
// //     }
// //     return false;
// // }

// int main()
// {
//     int n;
//     cin>>n;
//     long long x;
//     cin>>x;
//     long long a[n];
//     map <long long,int> pos;
//     for (int i=0;i<n;i++)
//     {
//         cin>>a[i];
//         pos[a[i]]=i;
//     }
//     for(int i=0;i<n;i++)
//     {
//         // if (check2sum(a,x-a[i],i,n))
//         // {
//         //     // cout<<check2sum(a,x-a[i],i,n);
//         //     cout<<i+1;
//         //     return 0;
//         // }
//         int first = i;
//         for (int j=i+1;j<n;j++)
//         {
//             long long sum2 = x - a[first];
//             if (pos.count(sum2 - a[j])!=0 && j!=first)
//             {
//                 if (pos[sum2-a[j]]!=j && pos[sum2-a[j]]!=first)
//                 {
//                     cout<<first+1<<" "<<j+1<<" "<<pos[sum2-a[j]]+1;
//                     return 0;
//                 }
//             }
//         }
//     }
//     cout<<"IMPOSSIBLE";
// }
