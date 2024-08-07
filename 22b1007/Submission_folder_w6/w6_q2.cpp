#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void cycle_printer(vector<int>& parent, int a, int b, int N)
{	
	int city;
	vector<int> ancestors_a;
	city = a;
	while(parent[city - 1] != N + 1)
	{
		ancestors_a.push_back(city);
		city = parent[city - 1];
	}
	ancestors_a.push_back(city);

	vector<int> ancestors_b;
	city = b;
	while(parent[city - 1] != N + 1)
	{
		ancestors_b.push_back(city);
		city = parent[city - 1];
	}
	ancestors_b.push_back(city);

	std::reverse(ancestors_a.begin(), ancestors_a.end());
	std::reverse(ancestors_b.begin(), ancestors_b.end());

	int length_to_be_compared = min(ancestors_a.size(), ancestors_b.size());
	int index;
	for(index = 0; index < length_to_be_compared; index++)
	{
		if(ancestors_a[index] != ancestors_b[index]) break;
	}

	int ancestor_index = index - 1;
	
	int count = ancestors_a.size() - 2 * ancestor_index + ancestors_b.size();
	std::cout << count << std::endl;
	
	for(int i = ancestor_index; i < ancestors_a.size(); i++)
	{
		std::cout << ancestors_a[i] << " ";
	}
	for(int i = ancestors_b.size() - 1; i >= ancestor_index; i--)
	{
		std::cout << ancestors_b[i] << " ";
	}

	std::cout << std::endl;

	return ;
	

}
int main()
{
	int N;
	long M;
	std::cin >> N >> M;

	vector<vector<int>> adjacency(N);

	for(long i = 0; i < M; i++)
	{
		int citya;
		int cityb;

		std::cin >> citya >> cityb;
		adjacency[citya - 1].push_back(cityb);
		adjacency[cityb - 1].push_back(citya);
	}

	vector<int> parent(N, 0); 
	//0 represent parent not found. 1 to N means corresponding vertex is parent. N + 1 measn root. 

	for(int i = 0; i < N; i++)
	{
		if(parent[i] == 0)
		{	
			int index = 0;
			vector<int> stack;
			parent[i] = N + 1;
			stack.push_back(i + 1);

			while(index < stack.size())
			{
				int city = stack[index];
				for(auto ele : adjacency[city - 1])
				{
					if(ele == parent[city - 1]) continue;
					if(parent[ele - 1] != 0)
					{
						//cycle printing and all these
						cycle_printer(parent, city, ele, N);
						return 0;
					} 
					else
					{
						parent[ele - 1] = city;
						stack.push_back(ele);
					}

				}
				index ++;
			}


		}

	}

	std::cout << "IMPOSSIBLE" << std::endl;
	return 0;
}
