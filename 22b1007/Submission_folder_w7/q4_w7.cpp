#include <iostream>
using namespace std;

int main()
{
	string s;
	std::getline(std::cin, s);

	int n = s.length();
	int* arr = new int[n];

	arr[0] = 0;
	int max = 0;
	int ini_for_max = 0;
	for(int i = 1; i < n; i++)
	{	

		int length = 0;
		if(i != 1 && max >= i)
		{
			int index = i - ini_for_max;
			length = std::min(arr[index], max - i + 1);
		}
		// std::cout << length << std::endl;
		while(i + length < n)
		{
			// std::cout << i << std::endl;
			if(s[i + length] == s[length])
			{
				length ++;
			}
			else{break;}
		}

		if(max < i + length - 1){max = i + length - 1; ini_for_max = i;}
		// std::cout << "max " << max << std::endl;
		arr[i] = length;
		if(i + length == n)
		{
			std::cout << i << " ";
		}
	}
	std::cout << n << std::endl;
}