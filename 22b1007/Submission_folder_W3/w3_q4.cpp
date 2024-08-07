#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	std::string initial;
	std::string final;
	std::getline(std::cin, initial);
	std::getline(std::cin, final);
	// std::cout<<final<<std::endl;
	int n, m;
	n = initial.size();
	m = final.size();
	// std::cout<<n<<" "<<m<<std::endl;

	int arr[m][n + 1];
	for(int i = 0; i < m; i++){arr[i][0] = i + 1;}
	// It is fixed size matrix which will be used to store.
	for(int i = 0; i < m; i++)
	{	int occurrence = n + 1;
		if(i == 0)
		{
			for(int j = 1; j <= n; j++)
			{
				if(initial[j - 1] == final[0]){occurrence = j; break;}
			}

			for(int j = 1; j <= n; j++)
			{
				if( j < occurrence ){arr[0][j] = j;}
				else
				{
					arr[0][j] = j - 1;
				}

			}
			continue;
		}


		for(int j = 1; j <= n; j++)
		{
			arr[i][j] = std::min(arr[i - 1][j] + 1, arr[i][j - 1] + 1);
			int another_case = arr[i - 1][j - 1];
			if (initial[j - 1] != final[i]) another_case ++;
			arr[i][j] = std::min(arr[i][j] , another_case);
		}

	}

	std::cout<<arr[m - 1][n]<<std::endl;
}