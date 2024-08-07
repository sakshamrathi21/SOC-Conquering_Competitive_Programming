#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void dfs_and_sorted(vector<vector<int>>& adjacency, vector<int>& visited, vector<int>& sorted, int root)
{
	for(auto ele : adjacency[root - 1])
	{
		if(visited[ele - 1] != 0) continue;
		visited[ele - 1] = 1;
		dfs_and_sorted(adjacency, visited, sorted, ele);
	}

	sorted.push_back(root);
	visited[root - 1] = sorted.size();
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
	}

	vector<int> visited(N, 0);
	//0 represent that the vertex is not visited.
	vector<int> sorted(N);
	//Do not push on this vector.

	for(int i = 0; i < N; i++)
	{
		if(visited[i] == 0)
		{	
			visited[i] = 1;
			dfs_and_sorted(adjacency, visited, sorted, i + 1);
		}
	}

	if(visited[0] > visited[N - 1])
	{
		vector<long> ways(N, 0);
		ways[0] = 1;

		for(int i = visited[0]; i > visited[N - 1]; i--)
		{
			int vertex = sorted[i - 1];
			for(auto ele : adjacency[vertex - 1])
			{
				int location = visited[vertex - 1];
				if(location < visited[N - 1]) continue;
				ways[ele - 1] += ways[vertex - 1];
				ways[ele - 1] = ways[ele - 1] % 1000000007;
			}
		}

		std::cout << ways[N - 1] << std::endl; 
	}
	else
	{
		std::cout << 0 << std::endl;
	}

}