#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int t;
	std::cin >> t;
	int* arr = new int[t];
	int* sorted = new int[t];
	for(int i = 0; i < t; i++)
	{
		std::cin >> arr[i];
		sorted[i] = arr[i];
	}

	std::sort(sorted, sorted + t);
	int* results = new int[t];
	int index  = 0;
	long long int A = 1;
	long long int B = 1;

	long long int ours = 1;

	while(index != t)
	{
		if(sorted[index] == ours)
		{
			results[index] = (A + B) % (1000000007);
			index ++;
		}

		long long int New_A = (2 * A + B) % (1000000007);
		long long int New_B = (4 * B + A) % (1000000007);

		A = New_A;
		B = New_B;

		ours ++;
	}

	for(int i = 0; i < t; i++)
	{
		int index = (int)(std::lower_bound(sorted, sorted + t, arr[i]) - sorted);
		std::cout<<results[index]<<std::endl;
	}

}