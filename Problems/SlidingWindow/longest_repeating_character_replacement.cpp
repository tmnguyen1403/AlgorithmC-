#include <map>

class Solution {
public:
    
    
    int characterReplacement(string s, int k) {
        uint16_t N = s.length();
        if (N <= 1) {
            return N;
        }
        
        auto max = [] (uint16_t &a, uint16_t& b)->uint16_t {
            if (a > b)
                return a;
            return b;
        };
        
        std::map<char, uint16_t> char_occurences;
        
        uint16_t left = 0;
        uint16_t right = 1;
        uint16_t max_occurence = 1;
        uint16_t max_length = 1;
        uint16_t length_substring = 1;
        ++char_occurences[s[0]];
        
        while (right < N) {
            ++char_occurences[s[right]];
            ++length_substring;
            max_occurence = max(max_occurence, char_occurences[s[right]]);
            
            if (length_substring - max_occurence <= k) {
                max_length = max(max_length, length_substring);
                
            } else {
                --char_occurences[s[left]];
                ++left;
                --length_substring;
            }
            ++right;
        }
        return max_length;
    }
};
