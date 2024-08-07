#include <iostream>
using namespace std;

int main()
{
	int number;
	std::cin >> number;
	for(int i = 0; i < number; i++)
	{
		int a,b,c;
		std::cin >> a >> b >> c;

		long long int b_power_c = 1;
		long long int power_b = b;
		while(c != 0)
		{
			if(c % 2 == 1)
			{
				b_power_c  *= power_b;
				
			}
			c = (c - c % 2)/2;
			power_b *= power_b;
			b_power_c = b_power_c % 1000000006;
			power_b = power_b % 1000000006;

		}

		long long int a_power_bc = 1;
		long long int power_a = a;

		while(b_power_c != 0)
		{
			if(b_power_c % 2 == 1)
			{
				a_power_bc  *= power_a;
				
			}
			b_power_c = (b_power_c - b_power_c % 2)/2;
			power_a *= power_a;
			a_power_bc = a_power_bc % 1000000007;
			power_a = power_a % 1000000007;

		}

		std::cout<<a_power_bc<<std::endl;
	}

	return 0;
}