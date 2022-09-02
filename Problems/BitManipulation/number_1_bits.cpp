class Solution {
public:
    int hammingWeight(uint32_t n) {
       int sum_bit = 0;
       while (n > 0) {
           sum_bit += (n & 1);
           n = n >> 1;
       }
        return sum_bit;
    }
};

