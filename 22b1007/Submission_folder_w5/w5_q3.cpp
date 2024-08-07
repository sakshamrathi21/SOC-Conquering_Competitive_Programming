#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iter;
	std::cin>>iter;
	for(int it = 0; it < iter; it++)
	{
		long long int x;
		std::cin >> x;
		do
		{	if( x < 10)
			{
				std::cout<<"No"<<std::endl; break;
			}
			int rem = x % 10;
			if( rem == 9 ){std::cout<<"No"<<std::endl; break;}
			x = (x - x % 10)/10 - 1;

		}
		while(x != 0);

		if( x == 0 ){std::cout<<"Yes"<<std::endl;}


	}
}