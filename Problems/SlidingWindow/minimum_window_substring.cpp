#include <map>
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length())
            return "";
        
        std::map<char, uint32_t> map_t, map_s;
        
        //init map
        for (auto &c : t)
            map_t[c] += 1;
        
        uint32_t min_length = 200000;
        uint32_t min_left = 0;
        
        uint32_t left = 0;
        uint32_t right = 0;
        
        uint32_t have = 0;
        uint32_t need = map_t.size();
        
        while (right < s.length()) {
            auto& c = s[right];
            if (map_t.find(c) != map_t.end()) {
                map_s[c] += 1;
                
                if (map_s[c] == map_t[c])
                    ++have;
                while (have == need) {
                    auto substr_length = right - left + 1;
                    if (substr_length <= min_length) {
                        min_left = left;
                        min_length = substr_length;
                    }
                    const auto& cl = s[left];
                    
                    if (map_s[cl] > 0) {
                        map_s[cl] -= 1;
                        if (map_s[cl] < map_t[cl]) {
                            --have;
                        }
                    }
                    ++left;
                }
            }
            ++right;
        }
        
        if (min_length == 200000)
            return "";
            
        return s.substr(min_left, min_length);
    }
};
