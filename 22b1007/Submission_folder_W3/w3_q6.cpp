#include <iostream>
#include <algorithm>
#include <queue>
#include <numeric>
using namespace std;

int main()
{
	int N, W;
	std::cin >> N >> W;

	int* weights = new int[N];
	int* values = new int[N];

	for(int i = 0; i < N; i++){std::cin >> weights[i] >> values[i];}
	int sum = std::accumulate(values, values + N, 0);
	int* arr = new int[sum + 1];
	int sum_of_weights = std::accumulate(weights, weights + N, 0);
	for(int i = 0; i <= sum; i++)
	{
		arr[i] = sum_of_weights + 1;
	}

	arr[0] = 0;

	int max = 0;

	for(int i = 0; i < N; i++)
	{
		vector<std::pair<int, int>> updates;
		for(int j = 0; j <= sum; j++)
		{
			if(arr[j] >= sum_of_weights + 1) continue;
			if (((arr[j] + weights[i]) < arr[values[i] + j]) && ((arr[j] + weights[i]) <= W))
			{
				updates.push_back(std::make_pair(j + values[i], arr[j] + weights[i]));
			} 
		}

		while(updates.size() != 0)
		{
			arr[updates.back().first] = updates.back().second;
			if(max < updates.back().first) max = updates.back().first;
			// std::cout<<updates.back().first;
			updates.pop_back();
		}

	}

	std::cout<<max<<std::endl;
}