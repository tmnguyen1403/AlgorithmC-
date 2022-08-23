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
#include <deque>

class Solution {
public:
    int max(int a, int b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }

    //DFS solution
    //Time: O(n)
    //Space: O(n) - worst case - unbalanced tree
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    //BFS solution - using deque to manage node
    //Time: O(n) - visiting all nodes
    //Space: O(2^d) - d is the depth of the tree
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        std::deque<TreeNode*> deqNodes;
        deqNodes.push_back(root);
        deqNodes.push_back(nullptr);
        int depth = 0;
        while (!deqNodes.empty()) {
            TreeNode * node = deqNodes.front();
            deqNodes.pop_front();
            if (node == nullptr) {
                depth += 1;
                if (deqNodes.size() >= 1)
                    deqNodes.push_back(nullptr);
            } else {
                if (node->left != nullptr) {
                    deqNodes.push_back(node->left);
                }

                if (node->right != nullptr) {
                    deqNodes.push_back(node->right);
                }
            }
        }
        return depth;
    }

};