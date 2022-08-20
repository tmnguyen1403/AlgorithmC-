#include <iostream>
#include <deque>
#include <vector>


std::vector<int> FindMaxSlidingWindow(std::vector<int>& nums, int window_size)
{
    std::deque<size_t> window; //stored index of elements in desceding order based on the value at the index
    std::vector<int> result;

    if (nums.empty()) {
        return result;
    }
    if (window_size > nums.size()) {
        window_size = nums.size();
    }

    for (int i = 0; i < window_size; ++i) {
        while (!window.empty() && nums[window.back()] < nums[i]) {
            window.pop_back();
        }
        window.push_back(i);
    }
    result.push_back(nums[window.front()]);

    for (int i = window_size; i < nums.size(); ++i) {
        while (!window.empty() && nums[window.back()] < nums[i]) {
            window.pop_back();
        }
        window.push_back(i);
        if (!window.empty() && i - window.front() >= window_size) {
            window.pop_front();
        }
        if (!window.empty()) {
            result.push_back(nums[window.front()]);
        }
    }
    return result;
}

void PrintList(std::vector<int> arr) {
    for(auto &element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
	std::vector<int> target_list {3, 2, 1, 2};
	std::vector< std::vector<int> > nums_list {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 
        {10, 6, 9, -3, 23, -1, 34, 56, 67, -1, -4, -8, -2, 9, 10, 34, 67}, 
        {4, 5, 6, 1, 2, 3}, 
        {9, 5, 3, 1, 6, 3}
    };

	for (int i = 0; i < target_list.size(); i++){
		std::cout << i + 1 << ". Original list:\t";
		PrintList(nums_list[i]);
		std::cout << "   Window size:\t\t" << std::to_string(target_list[i]) << std::endl;
		std::cout << "   Max:\t\t\t";
		std::vector<int> ouput = FindMaxSlidingWindow(nums_list[i], target_list[i]);
		PrintList(ouput);
		std::cout << "-----------------------------------------------------------------------------------------------------\n" << std::endl;
	}
}