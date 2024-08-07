#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long x;
    cin>>x;
    long long numbers[n];
    long long numbers_copy[n];
    for (int i=0;i<n;i++)
    {
        cin>>numbers[i];
        numbers_copy[i]=numbers[i];
    }
    sort(numbers,numbers+n);
    int l,r;
    l=0;
    r=n-1;
    while ((x!=numbers[l]+numbers[r]) && l!=r)
    {
        long long sum = numbers[l]+numbers[r];
        if (sum > x)
        {
            r--;
        }
        else if (sum < x)
        {
            l++;
        }
    }
    // cout<<numbers[l]<<" "<<numbers[r];
    if (l==r)
    {
        cout<<"IMPOSSIBLE";
    }
    else{
        int p1;
        int p2;

        for(int i=0;i<n;i++)
        {
            if (numbers[l]==numbers_copy[i])
            {
                p1=i;
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if (numbers[r]==numbers_copy[i] && p1!=i)
            {
                p2=i;
                break;
            }
        }
        cout<<p1+1<<" "<<p2+1;

        // -----------ALT----------------------------------
        // int j = 0;
        // bool found = false;
        // bool left = true;
        // while(p1==-1 || p2==-1)
        // {
        //     // if (!found)
        //     // {
        //     //     if (numbers[l]==numbers_copy[j] || numbers[r]==numbers_copy[j])
        //     //     {
        //     //         p1=j;
        //     //         cout<<j;
        //     //         found = true;
        //     //     }
        //     // }
        //     // else if (found && j!=p1)
        //     // {
        //     //     if (numbers[l]==numbers_copy[j] || numbers[r]==numbers_copy[j])
        //     //     {   
        //     //         p2=j;
        //     //         cout<<j;
        //     //     }
        //     // }


        //     // if (numbers[l]==numbers_copy[j] && p1==-1)
        //     // {
        //     //     p1=j;
        //     // }
        //     // if (numbers[r]==numbers_copy[j] && p2==-1)
        //     // {
        //     //     if (numbers[l]==numbers[r])
        //     //     {
        //     //         if (p1!=-1)
        //     //         {
        //     //             p2=j;
        //     //         }
        //     //     }
        //     //     else
        //     //     {
        //     //         p2=j;
        //     //     }
        //     // }
        //     j++;
        // }
        
    }
}