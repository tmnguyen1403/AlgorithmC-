class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        //Reserving the size of vector result first will reduce the time when the container needs to be resize due to adding new element
        result.resize(n+1);
        
        int max_element = 2;
        int start = 1;
        auto min = [](const int& a, const int& b) -> const int& {
            if (a <= b)
                return a;
            else
                return b;
        };
        
        while (start <= n) {
            auto end = min(n, max_element);
            for (int i=0; i < max_element >> 1; ++i) {
                result[start] += 1+ result[i];
                ++start;
                if (start > end) {
                    break;
                }
            }
            max_element = max_element << 1;
        }
        return std::move(result);
    }
};