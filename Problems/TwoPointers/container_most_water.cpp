class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right= height.size() - 1;
        int maxArea = 0;
        int currentArea = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                currentArea = height[left] * (right - left);
                ++left;
            } else {
                currentArea = height[right] * (right - left);
                --right;
            }
            if (maxArea < currentArea)
                maxArea = currentArea;
        }
        
        return maxArea;
    }
};