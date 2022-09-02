
/*
Solved with multi thread
*/

#include <thread>

class Solution {
public:
    
    void test(uint16_t n, int& result) {
        while (n > 0) {
           result += (n & 1);
           n = n >> 1;
       }
    }
    
    int hammingWeight(uint32_t n) {
       int sum_bit = 0;
        int first16 = 0;
        int second16 = 0;
        std::thread thread1(&Solution::test, this, n, std::ref(first16));
        std::thread thread2(&Solution::test, this, n >> 16, std::ref(first16));
        
        thread1.join();
        thread2.join();
        return first16 + second16;
    }
};