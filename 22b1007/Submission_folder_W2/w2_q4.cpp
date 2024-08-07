#include <unordered_map>
#include <algorithm>
#include <iostream>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::unordered_map<int, int> counter;
        std::vector<int> heap(nums.begin(), nums.begin() + k);
        std::make_heap(heap.begin(), heap.end());
        int length = nums.size();
        for(int i = 0; i < k; i++)
        {
            if (counter.find(nums[i]) == counter.end())
            {
                counter[nums[i]] = 1;
            }
            else{counter[nums[i]] ++;}
        }
        vector<int> maxer;
        int fin = k - 1;
        while(true)
        {
get_max:
            int maxElement = heap.front();
    
            if( counter.find(maxElement) == counter.end() || counter[maxElement] == 0 )
            {
                std::pop_heap(heap.begin(), heap.end());
                heap.pop_back();
                goto get_max;
            }

            maxer.push_back(maxElement);

            if( fin + 1 >= length ) break;

            if (counter.find(nums[fin + 1]) == counter.end())
            {
                counter[nums[fin + 1]] = 1;
            }
            else{counter[nums[fin + 1]] ++;}
            
            heap.push_back(nums[fin + 1]);
            std::push_heap(heap.begin(), heap.end());

            counter[nums[fin - k + 1]] --;

            fin ++;
            

        }
        
        return maxer;
        
    }
};
