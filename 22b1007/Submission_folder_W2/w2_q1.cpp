#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
	int n;
	std::cin>>n;
	int* arr = new int[n];
	int* arr2 = new int[n];  
	int* arr3  = new int[n];
	for(int i = 0; i < n; i++){std::cin>>arr[i]; arr2[i] = arr[i]; arr3[i] = -1;}

	std::sort(arr2, arr2 + n);
	
	int longest = 0;
	int starting = 0;
	for(int i = 0; i < n; i++)
	{
		int value = arr[i];
		int index = (int)(std::lower_bound(arr2, arr2 + n, value) - arr2);

		if (arr3[index] != - 1) 
		{
			if (arr3[index] >= starting)
			{
				starting = arr3[index] + 1;
			}
		}

		if ( i - starting + 1 > longest ) {longest = i - starting + 1;}
		arr3[index] = i;
	}

	std::cout<<longest<<std::endl;
}