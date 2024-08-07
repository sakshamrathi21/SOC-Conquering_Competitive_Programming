#include <bits/stdc++.h>
using namespace std;

bool check_cycle(int v, int parent, bool *visited, set<int> neighbours[])
{   
    if (visited[v] == true)
    {
        return true;
    }
    visited[v] = true;
    for (auto neighbour : neighbours[v])
    {
        if (neighbour != parent)
        {
            if (check_cycle(neighbour, v, visited, neighbours))
            {
                return true;
    }}}
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        set<int> neighbours[n];
        for (int i = 0; i < n; i++)
        {
            int v1 = i;
            int v2;
            cin >> v2;
            neighbours[v1].insert(v2 - 1);
            neighbours[v2 - 1].insert(v1);
        }  bool visited[n];
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
        int cycles = 0;
        int straights = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                if (check_cycle(i, -1, visited, neighbours))
                {
                    cycles++;
                }
                else
                {
                    straights++;
         }}}
        int max_dances = cycles + straights;
        int min_dances = cycles + (straights>0);
        cout<<min_dances<<" "<<max_dances<<"\n";
    }
}
