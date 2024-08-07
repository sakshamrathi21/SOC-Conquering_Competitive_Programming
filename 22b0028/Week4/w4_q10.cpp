#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    const int length = 10000001;
    vector<int> sieve(length, 0);

    for (int i = 2; i < length; ++i) {
        if (sieve[i] == 0 && (long long) i * i < length) {
            for (int j = i * i; j < length; j += i) {
                sieve[j] = i;
            }
        }
    }

    vector<int> primes;
    unordered_set<int> primeSet;
    for (int i = 2; i < length; ++i) {
        if (sieve[i] == 0) {
            primes.push_back(i);
            primeSet.insert(i);
        }
    }

    int t;
    cin >> t;

    vector<int> nums(t);
    for (int i = 0; i < t; ++i) {
        cin >> nums[i];
    }

    stringstream line1, line2;
    for (int i = 0; i < t; ++i) {
        int num = nums[i];
        if (primeSet.find(num) != primeSet.end()) {
            line1 << -1 << " ";
            line2 << -1 << " ";
        } else {
            bool found = false;
            int smallestPrime = sieve[num];
            int product = 1;
            int temp = num;
            while (temp != 1) {
                if (sieve[temp] != 0) {
                    if ((product % sieve[temp]) != 0) product *= sieve[temp];
                    temp = temp / sieve[temp];
                } else {
                    if (product % temp != 0) product *= temp;
                    temp = 1;
                }
            }
            product = product / smallestPrime;

            while (product > 1) {
                if (gcd(smallestPrime + product, num) == 1) {
                    line1 << smallestPrime << " ";
                    line2 << product << " ";
                    found = true;
                    break;
                } else {
                    if (sieve[product] != 0) {
                        product /= sieve[product];
                        smallestPrime *= sieve[product];
                    } else {
                        break;
                    }
                }
            }

            if (!found) {
                line1 << -1 << " ";
                line2 << -1 << " ";
            }
        }
    }

    cout << line1.str() << endl;
    cout << line2.str() << endl;

    return 0;
}
