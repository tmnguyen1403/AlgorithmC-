/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<array>
/*
Mysolution: The idea is to use DFS to check from the left bottom of the tree 
and the right bottom of the tree
At each level, the boundary is updated by finding the maximum value of the left branch
and the minimum value of the right branch
since this statement left_value < root.val < right_value has to be true for all level
*/
class Solution {
public:
    std::optional<int> max(std::array<int, 5> arr, int N) {
        int max_tmp = arr[0];
        for (int index = 1; index < N; ++index) {
            if (max_tmp < arr[index]) {
                max_tmp = arr[index];
            }
        }
        return max_tmp;
    }
    
    std::optional<int> min(std::array<int, 5> arr, int N) {
        int min_tmp = arr[0];
        for (int index = 1; index < N; ++index) {
            if (min_tmp > arr[index]) {
                min_tmp = arr[index];
            }
        }
        return min_tmp;
    }
    
    bool validateSubtree(TreeNode* root, std::optional<int>& maxLeft, std::optional<int>& minRight) {
        if (root == nullptr) {
            return true;
        }
        //leftside
        std::optional<int> localMaxLeft;
        std::optional<int> localMinRight;
        std::array<int, 5> values;
        int index = 0;
        values[index++] = root->val;
        
        bool isValid = validateSubtree(root->left, localMaxLeft, localMinRight);
        if (!isValid) {
            return false;
        }
        if (localMaxLeft.has_value()) {
            const auto& val = localMaxLeft.value();
            if (val >= root->val) {
                return false;
            }
            values[index++] = val;
        }
        if (localMinRight.has_value()) {
            const auto& val = localMinRight.value();
            values[index++] = val;
        }
        
        localMaxLeft.reset();
        localMinRight.reset();
        isValid = validateSubtree(root->right, localMaxLeft, localMinRight);
        if (!isValid) {
            return false; 
        }
        if (localMinRight.has_value()) {
            const auto& val = localMinRight.value();
            if (val <= root->val) {
                return false;
            }
            values[index++] = val;
        }
        
        if (localMaxLeft.has_value()) {
            const auto& val = localMaxLeft.value();
            values[index++] = val;
        }
       
        maxLeft = max(values, index);
        minRight = min(values, index);
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        std::optional<int> maxLeft;
        std::optional<int> minRight;
        return validateSubtree(root,  maxLeft, minRight);
    }
};