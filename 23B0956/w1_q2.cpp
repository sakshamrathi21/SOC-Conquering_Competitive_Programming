#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int maxcount = 1;
    int counter = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (i == s.length() - 1)
        {
            maxcount = max(maxcount, counter);
        }
        else
        {
            if ((s[i] != s[i + 1]))
            {
                maxcount = max(maxcount, counter);
                counter = 1;
            }
            else
            {
                counter++;
            }
        }
    }
    cout << maxcount;
}
//---------------------------------------------------------------Alt solution-----------------------------------------------------------------
// #include <iostream>
// #include <string>

// int main() {
//     std::string s;
//     std::cin >> s;
//     int maxcount = 1;
//     int counter = 1;

//     for (int i = 0; i < s.length(); i++) {
//         if (i < s.length() - 1 && s[i] == s[i + 1]) {
//             counter++;
//         } else {
//             maxcount = std::max(maxcount, counter);
//             counter = 1;
//         }
//     }

//     std::cout << maxcount;
//     return 0;
// }
