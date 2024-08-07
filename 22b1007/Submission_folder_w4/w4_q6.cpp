#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
	int t;
	std::cin >> t;
	for(int iterations = 0; iterations < t; iterations ++)
	{
		int n;
		std::cin >> n;
		std::vector<int> sizes;
		int count = 0;
		for(int i = 0; i < n; i++)
		{	
			int value;
			std::cin >> value;
			if(value != 1){count ++;}
			sizes.push_back(value);
		}

		if(count == 1)
		{
			std::cout << "first" << std::endl;
			continue;
		}

		if(count == 0)
		{
			if(n % 2 == 1){std::cout << "first" << std::endl; continue;}
			else if(n % 2 == 0){std::cout << "second" << std::endl; continue;}
		}

		int nim_sum = 0;
    	for(int i = 0; i < n; ++i) 
    	{
        	nim_sum ^= sizes[i];
    	}

    	// std::cout << nim_sum << std::endl;

    	if(nim_sum != 0)
    	{
    		std::cout << "first" << std::endl; continue;
    	}
    	else
    	{
    		std::cout << "second" << std::endl; continue;
    	}


	}
}