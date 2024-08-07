#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	long M;
	int K;

	std::cin >> N >> M >> K;
	vector<vector<int>> adjacency(N);
	for(long i = 0; i < M; i++)
	{	
		int vertexa, vertexb;
		std::cin >> vertexa >> vertexb;
		adjacency[vertexa - 1].push_back(vertexb);
		adjacency[vertexb - 1].push_back(vertexa);
	}

	vector<std::pair<int, int>> guards;
	for(int i = 0; i < K; i++)
	{
		int position, stamina;
		std::cin >> position >> stamina;
		guards.push_back({stamina, position});
	}

	std::sort(guards.begin(), guards.end());
	std::reverse(guards.begin(), guards.end());
	//This has been done so that the guards vector is in decreasing order
	//of stamina.

	int max_left_stamina = guards[0].first;
	vector<int> vertices(N, -1);

	int index_guard = 0;
	//Semantics : represent the guard to be considered still now. 
	
	vector<int> stack;
	int index = 0;
	//index represent the element on stack to be considered.

	
	int final_sum = 0;
	while(max_left_stamina >= 1)
	{
		//All but guards positions have been put.
		while(index_guard < K && guards[index_guard].first == max_left_stamina )
		{
			if(vertices[guards[index_guard].second - 1] < max_left_stamina) 
				{ stack.push_back(guards[index_guard].second); 
				  final_sum ++;
				  vertices[guards[index_guard].second - 1] = max_left_stamina;
				}

			index_guard ++;
		}

		//State of algo where we presume all concerned are pushed and the vertices well updated.
		int vertices_of_this_category = stack.size() - index;
		for(int i = 0; i < vertices_of_this_category; i++)
		{
			int vertex = stack[index];
			for(auto ele : adjacency[vertex - 1])
			{
				if(vertices[ele - 1] >= max_left_stamina - 1) continue;
				stack.push_back(ele);
				final_sum ++;
				vertices[ele - 1] = max_left_stamina - 1;
			}
			index ++;
		}
		max_left_stamina --;
	}

	std::cout << final_sum << std::endl;
	for(int i = 0; i < N; i++)
	{
		if(vertices[i] >= 0){std::cout << i + 1 << " ";}
	}
	std::cout << std::endl;
	
	return 0;
}