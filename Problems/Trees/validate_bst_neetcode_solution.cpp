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

/*
The idea is to test at the root level,
then traverse down left branch and right branch.
For left branch, update the right boundary since we want the left nodes always smaller than root
and vice verse for the right branch

*/
class Solution {
public:
    
    bool validateSubtree(TreeNode* root, TreeNode* left, TreeNode* right) {
        if (root == nullptr) {
            return true;
        }
        //leftside
        if (left) {
            if ( left->val >= root->val )
                return false;
        }   
        if (right) {
            if ( right->val <= root->val )
                return false;
        }
        return validateSubtree(root->left, left, root) && validateSubtree(root->right, root, right);
    }
    
    bool isValidBST(TreeNode* root) {
        return validateSubtree(root,  nullptr, nullptr);
    }
};