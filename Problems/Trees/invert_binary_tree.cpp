//https://leetcode.com/problems/invert-binary-tree/
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
    TreeNode* invertTree(TreeNode* root) {
        //use bfs recursive
        //at each level of the tree
        //swap the left and the right leaves
        //then continue moving down the tree using the leaf nodes
        //Stop condition: when node is null
        //Time complexity: O(n) with n is the length of the tree
        //Space complexity: O(n) with n is the length of the tree
        if (root == nullptr) {
            return root;
        }
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};