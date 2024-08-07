#include <iostream>
#include <stack>
using namespace std;

int main()
{	
	int t;
	std::cin >> t;
	for(int iter = 0; iter < t; iter++)
	{
		string s;
		std::getline(std::cin, s);
		std::getline(std::cin, s);

		long long int pos;
		std::cin >> pos; //pos of the element to be finded

		int n = s.length();

		int string_no = 0; //suspected string
		int length_of_string_no = n; 
		long long int residual = pos; 
		while(length_of_string_no < residual) 
		{
			residual -= length_of_string_no;
			length_of_string_no --;
			string_no ++;
		}

		int characters_to_remove = string_no;

		std::stack<char> stack1;
		int index_of_stack2 = 0;

		while(characters_to_remove > 0 && index_of_stack2 < n)
		{
			if(stack1.size() == 0){stack1.push(s[index_of_stack2]); index_of_stack2 ++; continue;}
			if(stack1.top() > s[index_of_stack2]){if(stack1.size() == 0){std::cout << "Hello1" << std::endl;} stack1.pop(); characters_to_remove --; continue;}
			stack1.push(s[index_of_stack2]); index_of_stack2 ++; continue;
		}

		while(index_of_stack2 < n)
		{
			stack1.push(s[index_of_stack2]);
			index_of_stack2 ++;
		}

		while(characters_to_remove + length_of_string_no - residual > 0)
		{
			if(stack1.size() == 0){std::cout << "Hello2" << std::endl;} 
			stack1.pop();
			characters_to_remove --;
		}

		if(stack1.size() == 0){std::cout << "Hello3" << std::endl;}
		std::cout << stack1.top();


	}
	std::cout << std::endl;
}