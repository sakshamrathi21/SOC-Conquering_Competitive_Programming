#include <iostream>
#include <stdexcept>
using namespace std;

// Function to perform extended Euclidean algorithm
long long int extended_gcd(long long int  a, long long int b,long long  int &x, long long int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long int x1, y1;
    long long int gcd = extended_gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

// Function to find modular inverse
long long int modular_inverse(long long int a, long long int m) {
    long long int x, y;
    long long int gcd = extended_gcd(a, m, x, y);
    if (gcd != 1) {
        throw std::invalid_argument("Inverse doesn't exist");
    } else {
        return (x % m + m) % m;
    }
}


int main()
{
    int n, m;
    std::cin >> n >> m;
    n = n + m - 1;
    long long int value = 1;
    for(int i = 1; i <= m; i++)
    {
        long long int multiplier = (((n - m + i) % 1000000007) * modular_inverse(i, 1000000007)) % 1000000007;
        value = (value * multiplier) % 1000000007;
    }

    std::cout << value << std::endl;
}