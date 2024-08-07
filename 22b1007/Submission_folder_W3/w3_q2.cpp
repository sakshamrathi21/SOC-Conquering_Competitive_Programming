#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int n, t;
	std::cin >> n >> t;
	long long int* arr = new long long int[n];
	long long int min = 1000000000000;
	for(int i = 0; i < n; i++){std::cin >> arr[i]; if(min > arr[i]){min = arr[i];}}
	// for(int i = 0; i < n; i++){std::cout << arr[i] << std::endl;; }
		
	long long int lo = 0;
	long long int hi = min * t;

	while(lo + 1< hi)
	{
		long long int mid = (lo + hi)/2;
		long long int count = 0;
		for(int i  = 0; i < n; i++)
		{
			count += mid/arr[i];
		}

		if(count >= t){hi = mid;}
		else{lo = mid;}
		// std::cout<<"lo : "<<lo<<" hi : "<<hi<<std::endl;

	}
	std::cout<<hi<<std::endl;






















	// for(int i = 0; i < n; i++)
	// {
	// 	std::cin >> arr[i];
	// 	pq.push(std::make_pair( - arr[i], i));
	// }


	// int time_max = 0;
	// for(int i = 0; i < t; i++)
	// {
	// 	long long int time = - pq.top().first;
	// 	if(time_max < time){time_max = time;}
	// 	int index = pq.top().second;
	// 	pq.pop();
	// 	pq.push(std::make_pair(- time - arr[index], index));
	// }

	// std::cout<<time_max<<std::endl;

}