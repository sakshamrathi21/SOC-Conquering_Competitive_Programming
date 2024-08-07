#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	std::getline(std::cin, s);

	int longest = 0;
	int count = 0;

	int size = s.size();
	int* arr = new int[size + 1];
	arr[size] = 0;
	for(int i = size - 1; i >= 0; i--)
	{
		if(s[i] == ')'){arr[i] == 0; continue;}
		int to_check = i + 1;
		while(1)
		{
			if(to_check >= size){arr[i] = 0; break;}
			if(s[to_check] == ')'){arr[i] = to_check - i + 1 + arr[to_check + 1]; break;}
			else
			{
				if(arr[to_check] == 0){arr[i] = 0; break;}
				else{to_check += arr[to_check];}
			}
		}

		if(longest < arr[i]){count = 1; longest = arr[i];}
		else if(longest == arr[i]){count += 1;}

	}

	// for(int i = 0; i < size; i++)
	// {
	// 	std::cout << arr[i] << " ";
	// }
	// std::cout << std::endl;
	std::cout << longest << " ";
	if(longest == 0){std::cout<< 1 << std::endl;}
	else{std::cout << count << std::endl; }

	delete (char*)arr;
	return 0;
}