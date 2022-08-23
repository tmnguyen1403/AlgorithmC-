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
    int length_longest_path;
    Solution() {
        this->length_longest_path = 0;
    }
    //
    int max(int a, int b) {
        return a > b ? a : b;
    }

    //Time complexity: O(n) - visiting all nodes
    //Space complexity: O(n) - worst case - unbalanced tree
    int maxDiameter(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int maxDepthLeft = maxDiameter(root->left);
        int maxDepthRight = maxDiameter(root->right);
        this->length_longest_path = max(this->length_longest_path, maxDepthLeft + maxDepthRight);
        return 1 + max(maxDepthLeft, maxDepthRight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        maxDiameter(root);
        return this->length_longest_path;
    }
};