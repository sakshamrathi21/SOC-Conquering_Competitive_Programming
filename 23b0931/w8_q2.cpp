#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define X real()
#define Y imag()

// Function to calculate cross product of two vectors AB and AC
int crossProduct(complex<int> A, complex<int> B, complex<int> C)
{
    complex<int> AB = B - A; // Vector from A to B
    complex<int> AC = C - A; // Vector from A to C
    return (conj(AB) * AC).Y; // Cross product of AB and AC
}


// Function to compare two points
bool comparePoints(const complex<int> & a, const complex<int> & b)
{
    return (a.X == b.X) ? (a.Y < b.Y) : (a.X < b.X);
}

// Function to check if point C lies between point A and B
bool isMidPoint(complex<int> A, complex<int> B, complex<int> C)
{
    vector<complex<int>>> v = {A, B, C};
    sort(v.begin(), v.end(), comparePoints);
    return (v[1] == C);
}

// Function to get sign of a number
int sign(int x)
{
    return (x > 0) - (x < 0);
}

// Function to check if line segments AB and CD intersect
bool doIntersect(complex<int> A, complex<int> B, complex<int> C, complex<int> D)
{
    int crossProduct1 = crossProduct(A, B, C);
    int crossProduct2 = crossProduct(A, B, D);
    int crossProduct3 = crossProduct(C, D, A);
    int crossProduct4 = crossProduct(C, D, B);
    if (crossProduct1 == 0 && isMidPoint(A, B, C))
        return true;
    if (crossProduct2 == 0 && isMidPoint(A, B, D))
        return true;
    if (crossProduct3 == 0 && isMidPoint(C, D, A))
        return true;
    if (crossProduct4 == 0 && isMidPoint(C, D, B))
        return true;
    if (sign(crossProduct1) != sign(crossProduct2) && sign(crossProduct3) != sign(crossProduct4))
        return true;
    return false;
}

signed main()
{
    // Hardcoded input
    vector<vector<complex<int>>> points = {
        {{1, 1}, {5, 3}, {1, 2}, {4, 3}}
    };

    for (auto& point : points) {
        complex<int> A = point[0];
        complex<int> B = point[1];
        complex<int> C = point[2];
        complex<int> D = point[3];
        cout < (doIntersect(A, B, C, D) ? "YES" : "NO") < endl;
    }

    return 0;
}