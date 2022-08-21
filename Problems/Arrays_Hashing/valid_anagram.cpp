#include <string>
#include <map>
#include <algorithm>>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        /*First approach
        Sort the two string - O(nlogn) - time complexity
        Then compare the two sorted string - O(n)
        */
        if (s.length() != t.length()) {
            return false;
        }
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        for (size_t index=0; index < s.length(); ++index) {
            if (s[index] != t[index]) {
                return false;
            }
        }
        return true;
    }
    bool isAnagram(std::string s, std::string t) {
       /*Second approach
       Used mapped to stored the letters of the first string - s
       Iterate through the second string and checked if t has the same number of chars
       */
      if (s.length() != t.length()) {
          return false;
      }
      std::map<char, uint16_t> char_counters;
      for (const char& c: s) {
          if (char_counters.find(c) == char_counters.end()) {
              char_counters.insert(std::pair<char, uint16_t>(c, 0));
          }
          char_counters[c] += 1;
      }
      for (const char& c: t) {
          if (char_counters.find(c) == char_counters.end() || char_counters[c] == 0) {
              return false;
          }
          char_counters[c] -= 1;
      }
      return true;
    }
};