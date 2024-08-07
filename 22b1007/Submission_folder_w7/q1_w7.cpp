#include <iostream>
#include <stack>
#include <vector>
using namespace std;


class segment_tree
{
public:
	long long int* arr;
	int size;
	segment_tree(int n)
	{
		int x = 1;
		while(x < n)
		{
			x = x * 2;
		}
		// std::cout << "init" <<std::endl;
		arr = new long long int[2 * x - 1];
		// std::cout << "init" <<std::endl;
		for(int i = 0; i < 2 * x - 1; i++)
		{
			arr[i] = 0;
		}
		
		size = x;

	}

	void change_by(int index, int quantity)
	{
		index = index + size - 1;
		while(index > 0)
		{
			arr[index - 1] += quantity;
			index = index/2;
		}
		arr[index - 1] += quantity;
		return ;
	}

	long long int solve_query(int index, int range_left, int range_right, int ini, int fin)
	{
		if(range_left >= ini && range_right <= fin)
		{
			return arr[index - 1];
		}
		if(range_left > fin || range_right < ini)
		{
			return 0;
		}

		long long int sum = 0;
		sum += solve_query(2 * index, range_left, (range_left + range_right)/2, ini, fin);
		sum += solve_query(2 * index + 1, (range_left + range_right)/2 + 1, range_right, ini, fin);
		return sum;
	}

};
int main()
{
	int n, q;
	std::cin >> n >> q;
	segment_tree x(n);
	for(int i = 0; i < n; i++)
	{	
		int value;
		std::cin >> value;
		x.change_by(i + 1, value); 
	}

	for(int i = 0; i < q; i++)
	{
		int ini, fin;
		std::cin >> ini >> fin;

		std::cout << x.solve_query(1, 1, x.size, ini, fin) << std::endl;
	}


}