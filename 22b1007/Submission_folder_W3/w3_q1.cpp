#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	std::cin>> n;
	int* arr = new int[n];
	long long int deadlines = 0;
	for(int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
		int value;
		std::cin >> value;
		deadlines += value;
	}

	std::sort(arr, arr + n);
	long long int sum = 0;
	long long int value = 0;
	for(int i = 0; i < n; i++)
	{
		value += arr[i];
		sum += value; 
	}

	std::cout<<deadlines - sum<<std::endl;
}

