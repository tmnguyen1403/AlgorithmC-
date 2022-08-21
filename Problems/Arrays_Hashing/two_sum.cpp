#include <vector>
#include <map>

class Solution {
public:
    /*
    First approach: two nested loop - at every element, check the rest of the array 
    for the second element that sum of the two elements equal the target
    Time complexity: O(n^2)
    Space complexity: O(1)
    */
   /*
   Second apprach: hashmap <num, index>
   one loop iterating through each element in the nums array
   At each element, take the difference between the target and the current element.
   Check in the map wheter there is a difference.
   If yes, return the indices of the difference in the map and the current element.
   Otherwise, adding the index of the current element to the map

    Time: O(n) - iterating through element; O(1) - accessing(read, write) the map
    Space: (O(n)) - storing indices of n elments
   */
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, size_t> seen_map;
        std::vector<int> result;

        for (size_t index=0; index < nums.size(); ++index) {
            int diff = target - nums[index];
            if (seen_map.find(diff) != seen_map.end()) {
                result.push_back(seen_map[diff]);
                result.push_back(index);
                break;
            }
            else {
                seen_map.insert(std::pair<int, size_t>(nums[index], index));
            }
        }
        return result;
    }
};