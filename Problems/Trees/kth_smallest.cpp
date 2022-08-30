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
class Solution {
public:
    bool getKthSmallest(TreeNode *root, int& currentIndex, int k, int& result) {
        if (root == nullptr)
            return false;
        auto isFound = getKthSmallest(root->left, currentIndex, k, result);
        if (isFound) {
            return true;
        }
        
        currentIndex += 1;
        if (currentIndex == k) {
            result = root->val;
            return true;
        }
        return getKthSmallest(root->right, currentIndex, k, result);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int pos = 0;
        int result = 0;
        getKthSmallest(root, pos, k, result);
        return result;
    }
};