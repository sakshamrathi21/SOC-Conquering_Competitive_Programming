#include <iostream>
using namespace std;

int max_repet(string s)
{
    if (s.empty())
        return 0; // handle empty string case

    int max_count = 1;
    int count = 1;
    for (int i = 1; i < s.length(); i++) // start from 1 instead of 0
    {
        if (s[i] == s[i - 1])
            count++;
        else
            count = 1;

        max_count = max(count, max_count); // update max_count outside the else block
    }
    return max_count;
}

int main()
{
    string p;
    cin >> p;
    cout << max_repet(p) << endl;
}