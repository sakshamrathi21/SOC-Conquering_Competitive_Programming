#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int n;
    std::cin>>n;
    std::vector<int> teller(n, 0);
    for(int i = 0; i < n - 1; i++)
    {
        int value;
        std::cin >> value;
        teller[value - 1] = 1;
    }
    int i = 0;
    for(auto ele : teller)
    {
        if(ele == 0) {std::cout<<i + 1<<std::endl; return 0;}
        i++;
    }
    return 0;
}

