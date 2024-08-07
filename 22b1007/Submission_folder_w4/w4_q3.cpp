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
	int n;
	std::cin >> n;
	int* arr_a = new int[n];
	int* arr_b = new int[n];
	int maximum = -1;
	for(int i = 0; i < n; i++)
	{
		std::cin >> arr_a[i];
		std::cin >> arr_b[i];
		if(maximum < arr_a[i]) maximum = arr_a[i];
		if(maximum < arr_b[i]) maximum = arr_b[i];		
	}

	long long int* arr_mod = new long long int[maximum];
	long long int* arr_inv = new long long int[maximum];
	long long int  arr_modulus = 1;
	for(int i = 1; i <= maximum; i++)
	{
		arr_mod[i - 1] = (i * arr_modulus) % 1000000007;
		arr_modulus = arr_mod[i - 1];
		arr_inv[i - 1] = modular_inverse(arr_mod[i - 1], 1000000007); 
	}

	for(int i = 0; i < n; i++)
	{	if(arr_b[i] == 0)
		{
			std::cout << 1 << std::endl;
			continue;
		}
		std::cout << (((arr_mod[arr_a[i] - 1] * arr_inv[arr_b[i] - 1]) % 1000000007) * arr_inv[arr_a[i] - arr_b[i] - 1]) % 1000000007 << std::endl;
	}


}