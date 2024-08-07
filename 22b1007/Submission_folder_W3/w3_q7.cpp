#include <iostream>
#include <algorithm>
#include <queue>
#include <numeric>
using namespace std;

int main()
{
	int x, n;
	std::cin >> x >> n;
	int* arr = new int[n];
	std::priority_queue<int> heap;
	long long int cost = 0;
	int size = n;
	for(int i = 0; i < n; i++){int value; std::cin >> value; heap.push( - value);}
	while(size > 1)
	{
		int length = 0;
		length +=  - heap.top();
		heap.pop();
		length +=  - heap.top();
		heap.pop();
		cost += length;
		heap.push( - length);
		size = size - 1;
	}

	std::cout<<cost<<std::endl;

}