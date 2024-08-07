#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
  int n, x;
  std::cin >>n >>x;
  int* arr = new int[n];
  vector<std::pair<int, int>> vec; 
	for(int i = 0; i < n; i++)
	{
		std::cin>>arr[i];
		vec.push_back(std::make_pair(arr[i], i));
	}
  std::sort(vec.begin(), vec.end());

  for(int k = 0; k < n - 2; k++)
  { 
  	int value = x - vec[k].first;
  	int left = k + 1;
	int right = n - 1;
	while(true)
	{
		if(left == right){break;}
		if(vec[left].first + vec[right].first == value){break;}
		if(vec[left].first + vec[right].first > value){right = right - 1; continue;}
		else{left += 1; continue;}
	}
	if( left != right)
	{
		std::cout<<vec[left].second + 1<<" "<<vec[right].second + 1<<" "<<vec[k].second + 1<<std::endl;
		return 0;	
	}
	
  }

  std::cout<<"IMPOSSIBLE"<<std::endl;
}

