#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
int main()
{
  std::string line;
  std::getline(std::cin, line);
  int i = 0;
  char last;
  int count = 0;
  int max = -1;
 
  for(auto ele : line)
  {
    if( i == 0) {last = ele; count ++; i++; continue;}
    if( ele == last){count ++;}
    else{if( max < count) max = count; last = ele; count = 1;}
    i++;
  }
 
  if( max < count) max = count;
  std::cout<<max<<std::endl;
  return 0;  
}

