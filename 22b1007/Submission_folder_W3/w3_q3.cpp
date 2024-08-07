#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int n;
	std::cin >> n;

	long long int* arr = new long long int[n + 1];
	arr[0] = 1;
	for(int i = 1; i <= n; i++)
	{	
		long long int count = 0;
		for(int j = 1; (i >= j) && (j <= 6); j++)
		{
			count += arr[i - j];
			count = count % (1000000007);
		}
		arr[i] = count;
	}

	std::cout<<arr[n]<<std::endl;
}