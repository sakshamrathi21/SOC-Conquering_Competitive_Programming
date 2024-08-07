#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	int n;
	std::cin >> n;
	int* arr = new int[n];
	for(int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	std::sort(arr, arr + n);
	int index = (n  + n % 2)/2 - 1;
	int value = arr[index];

	long long int count = 0;
	for(int i = 0; i < n; i++)
	{
		count += abs(value - arr[i]);
	}
	std::cout<<count<<std::endl;
}

