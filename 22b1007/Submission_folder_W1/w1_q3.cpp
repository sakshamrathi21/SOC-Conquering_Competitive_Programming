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
        int64_t n; 
        std::cin >> n;
        int64_t k;
        std::cin >> k;
     
        if(n % 2 == 0){std::cout << "Yes\n";}
        else{if(k % 2 == 1){std::cout << "Yes\n";}else{std::cout << "No\n";}}
      }
      return 0;
    }
