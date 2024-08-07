#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long x1 = 1, y1 = 1, x2 = 5, y2 = 3, x3 = 2, y3 = 3;

    long long crossProduct = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    if (crossProduct < 0)
        cout << "RIGHT" << endl;
    else if (crossProduct > 0)
        cout << "LEFT" << endl;
    else
        cout << "TOUCH" << endl;

    return 0;
}