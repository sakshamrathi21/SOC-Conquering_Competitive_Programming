#include <iostream>
using namespace std;

int main()
{
	long long int n;
	std::cin >> n;

	long long int final_answer = 0;
	long long int last_considered = 0;

	while(last_considered < n)
	{
		long long int bucket = n/(last_considered + 1);
		long long int highest = n/bucket;
		// std::cout << last_considered << " " << highest << " " << bucket << std::endl;
		long long int expression;
		if(((last_considered + 1 + highest)) % 2 == 0)
		{
			expression = (((last_considered + 1 + highest)/2 % 1000000007) * ((highest - last_considered) % 1000000007));
		}
		else
		{
			expression = (((last_considered + 1 + highest) % 1000000007) * ((highest - last_considered)/2 % 1000000007));
		}
		// std::cout<<(((expression) % 1000000007) * (bucket % 1000000007)) % 1000000007<<std::endl;
		
		final_answer += (((expression) % 1000000007) * (bucket % 1000000007)) % 1000000007;
		final_answer = final_answer % 1000000007;

		last_considered = highest;
	}

	std::cout << final_answer << std::endl;
}