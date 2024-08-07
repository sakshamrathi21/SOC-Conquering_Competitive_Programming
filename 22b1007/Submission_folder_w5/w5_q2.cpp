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
	  int n;
	  std::cin >> n;
	  long long int min = 0;
	  long long int count_min = 1;
	  long long int max = 0;
	  long long int count_max = 0;
	  for(int i = 0; i < n; i++)
	  {
	  	int value;
	  	std::cin>> value;
	  	long long int tempMin = min;
	  	long long int tempMax = max;
	  	min = min + value;
	  	max = std::max(abs(min), abs(max + value));
	  	//std::cout<<min<<" "<<max<<std::endl;
	  	long long int tcount_min = 0;
	  	long long int tcount_max = 0;

	  	if( min == tempMin + value){tcount_min += count_min;}
	  	if( min == abs(tempMin + value)){tcount_min += count_min;}
	  	if( min == tempMax + value){tcount_min += count_max;}
	  	if( min == abs(tempMax + value)){tcount_min += count_max;}

	  	if( max == tempMin + value){tcount_max += count_min;}
	  	if( max == abs(tempMin + value)){tcount_max += count_min;}
	  	if( max == tempMax + value){tcount_max += count_max;}
	  	if( max == abs(tempMax + value)){tcount_max += count_max;}

	  	if(min == max){tcount_min = 0;}
	  	tcount_min = tcount_min % 998244353;
	  	tcount_max = tcount_max % 998244353;
	  	count_min = tcount_min;
	  	count_max = tcount_max;
	  }

	  std::cout<<count_max<<std::endl;
	}
}