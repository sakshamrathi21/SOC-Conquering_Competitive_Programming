#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	std::cin >> n;
	int* arr = new int[n];
	for(int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	double expectation = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(arr[j] >= arr[i])
			{
				expectation += (1.0/arr[i])*(arr[i] - 1)*(1.0/2)*(arr[i])*(1.0/arr[j]);
			}
			else
			{
				expectation += (1.0/arr[i])*(arr[j] - 1)*(1.0/2)*(arr[j])*(1.0/arr[j]);
				expectation += (1.0/arr[i])*(arr[i] - arr[j]);

			}

		}

	}

    std::cout << std::fixed << std::setprecision(6) << expectation << std::endl;
}