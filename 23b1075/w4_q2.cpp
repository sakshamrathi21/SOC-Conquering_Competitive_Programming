#include <iostream>

using std::cout;
using std::endl;

const int MOD = 1e9 + 7;
const int TWO_MOD_INV = 500000004;

/** @return The sum of all numbers in [start, end] mod MOD. */
long long total_sum(long long start, long long end) {
	return ((((end - start + 1) % MOD) * ((start + end) % MOD) % MOD) *
	        TWO_MOD_INV % MOD);
}

int main() {
	long long n;
	std::cin >> n;

	long long total = 0;
	long long at = 1;
	while (at <= n) {
		long long add_amt = n / at;  // Our divisor to process
		// The largest number that still has the same value of q
		long long last_same = n / add_amt;

		total = (total + add_amt * total_sum(at, last_same)) % MOD;
		at = last_same + 1;
	}

	cout << total << endl;
}
//at=1
// [20,10,6,5,4,3,2,2,2,2,1,1,1,1,1,1,1,1,1,1]