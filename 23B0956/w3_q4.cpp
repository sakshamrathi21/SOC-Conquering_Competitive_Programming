#include <bits/stdc++.h>
using namespace std;

int cmp(int a, int b)
{
    if (a == b)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    string s1;
    string s2;
    cin >> s1 >> s2;
    int m = s1.length();
    int n = s2.length();
    int distance[m + 1][n + 1];
    for (int a = 0; a < m + 1; a++)
    {
        for (int b = 0; b < n + 1; b++)
        {
            if (a == 0 || b == 0)
            {
                distance[a][b] = a + b;
            }
            else
            {
                distance[a][b] = min({distance[a][b - 1] + 1, distance[a - 1][b] + 1, distance[a - 1][b - 1] + cmp(s1[a-1],s2[b-1])});
            }
            // cout<<distance[a][b]<<" ";
        }
        // cout<<"\n";
    }
    
    cout << distance[m][n];
}