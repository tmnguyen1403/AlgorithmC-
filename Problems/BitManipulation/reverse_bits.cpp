class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for(uint8_t i = 0; i < 32; ++i) {
            result += (n & 1) << (31 - i);
            n = n >> 1;
        }
        return result;
    }
};