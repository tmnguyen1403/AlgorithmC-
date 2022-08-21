#include <map>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::map<int, bool> seen;
        for (const auto& num: nums) {
            if (seen.find(num) != seen.end()) {
                return true;
            }
            else {
                seen.insert(std::pair<int, bool>(num, true));
            }
        }
        return false;
    }
};