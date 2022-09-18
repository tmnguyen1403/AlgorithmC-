class Solution {
public:
    int16_t binarySearch(vector<int>& nums, const int& target, int16_t left, uint16_t right) {
        while (left < right) {
            auto mid = left + (right - left)/2;
            if (target > nums[mid])
                left = mid + 1;
            else
                right = mid;
        }
        if (target == nums[left])
            return left;
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        //find the position of the smallest element in the rotated sorted array
        //after searching, left is the position of the smallest element
        if (nums.size() == 1) {
            return target==nums[0] ? 0 : -1;
        }
        int16_t left = 0;
        int16_t right = nums.size() - 1;
        int last_num = nums[right];
        while (left < right) {
            auto mid = left + (right - left)/ 2;
            if (nums[mid] > last_num)
                left = mid + 1;
            else
                right = mid;
        }
        
        //perform binary search on [0, n-left] and [n-k+1, n)
        int16_t target_position = - 1;
        if (target >= nums[0] && left > 0)
            target_position = binarySearch(nums, target, 0, left - 1);
        else if (target <= last_num)
            target_position = binarySearch(nums, target, left, nums.size()-1);
        
        return target_position;
    }
};
