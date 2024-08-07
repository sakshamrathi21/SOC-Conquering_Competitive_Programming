#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	int n, x;
	std::cin >> n >> x;
	int* arr = new int[n];
	vector<std::pair<int, int>> vec; 
	for(int i = 0; i < n; i++)
	{
		std::cin>>arr[i];
		vec.push_back(std::make_pair(arr[i], i));
	}


	int left = 0;
	int right = n - 1;
	std::sort(vec.begin(), vec.end());
	while(true)
	{
		if(left == right){std::cout<<"IMPOSSIBLE"<<std::endl; return 0;}
		if(vec[left].first + vec[right].first == x){std::cout<<vec[left].second + 1<<" "<<vec[right].second + 1<<std::endl; return 0;}
		if(vec[left].first + vec[right].first > x){right = right - 1; continue;}
		else{left += 1; continue;}
	}

}