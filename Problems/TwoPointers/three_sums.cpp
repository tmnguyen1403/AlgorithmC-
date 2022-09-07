#include <map>
#include <algorithm>
#include <iostream>

class Solution {
public:
     /*
        1. Sort the array
        2. Assigning the first value by looping through the array
        3.  using left pointer and right pointer to find the other two values
        4. if sum of the three is greater than zero, move right pointer to the left
        else ,move left pointer to the right
        
        
        Time complexity:
        outer loop for first value: O(n)
            twosum(O(n))
        
        -->O(n^2)
        */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int firstPointer = 0;
        
        const auto N = nums.size();
        std::sort(nums.begin(), nums.end());
        while (firstPointer <= N - 3) {
            auto leftPointer = firstPointer + 1;
            auto rightPointer = N - 1;
            while (leftPointer < rightPointer) {
                auto total = nums[firstPointer] + nums[leftPointer] + nums[rightPointer];
                if (total > 0) {
                    rightPointer -= 1;
                }
                else if (total < 0) {
                    leftPointer += 1;
                }
                else {
                    vector<int> r3{0,0,0};
                    r3[0] = nums[firstPointer];
                    r3[1] = nums[leftPointer];
                    r3[2] = nums[rightPointer];
                    result.push_back(std::move(r3));
                    rightPointer -= 1;
                    leftPointer += 1;
                    while (leftPointer < rightPointer  && nums[leftPointer] == nums[leftPointer-1])
                        ++leftPointer;
                    while (rightPointer > leftPointer  && nums[rightPointer] == nums[rightPointer+1])
                        --rightPointer;
                }
            }
            firstPointer += 1;
            while (firstPointer <= N - 3 && nums[firstPointer] == nums[firstPointer-1])
                ++firstPointer;
        }
        
        return std::move(result);
    }
};