#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;

int main()
{
  int iterations;
  std::cin >> iterations;
  for(int iter = 0; iter < iterations; iter++)
  {
    int l, r;
    std::cin>>l>>r;
    int number  = l;
    int best;
    int max_dif = -1;

    if(r - l >= 100)
    {
        if ( l % 100 > 9 ){std::cout << (l - l % 100) + 109 <<std::endl; continue;}
        else{std::cout << (l - l % 100) + 90 <<std::endl; continue;}
    }
    for(number = l; number <= r; number++)
    { 
      int min = 10; int max = -1;
      int value = number;
      while(value != 0)
      {
        int digit = value % 10;
        value = (value - digit)/10;
        if(max < digit) max = digit;
        if(min > digit) min = digit;
      }

      if(max_dif < max - min) {max_dif = max - min; best = number; }  
    }
    std::cout<<best<<std::endl;
  }
  
  
}
