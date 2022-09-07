#include <unordered_map>
#include <iostream>


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const auto& N = s.length();
        if (N <= 1) {
            return N;
        }
        
        auto max = [] (uint16_t a, uint16_t b) -> uint16_t {
            return a > b ? a : b;
        };
        
        std::unordered_map<char, uint16_t> seen_char; //store index of the scanned character
        seen_char.reserve(128);
        uint16_t left = 0;
        uint16_t runner = left + 1;
        uint16_t max_length = 1;
                
        seen_char[s[0]]=0;
        
        while (runner < N) {
            const auto& c = s[runner];
            if (seen_char.find(c) != seen_char.end()) {
                left = max(left, seen_char[c] + 1);
            }
            seen_char[c] = runner;
            ++runner;
            max_length = max(max_length, runner - left);
        }
        
        return max_length;
    }
};           