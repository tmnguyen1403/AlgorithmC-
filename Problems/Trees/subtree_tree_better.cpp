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
#include <queue>

class Solution {
public:
    
    void findNode(TreeNode* root, int val, std::queue<TreeNode*>& sameQueue) {
        if (root == nullptr) {
            return;
        }
        if (root->val == val) {
            sameQueue.emplace(root);
        }
        findNode(root->left, val, sameQueue);
        findNode(root->right, val, sameQueue);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) {
            return true;
        }
        if (root == subRoot) {
            return true;
        }
        //Assuming that the value of each TreeNode is unique
        //Find the node that has the same value with the subRoot

        std::queue<TreeNode*> sameQueue;
        findNode(root, subRoot->val, sameQueue);
        while (!sameQueue.empty()) {
            if (isSameTree(sameQueue.front(), subRoot)) {
                return true;
            }
            sameQueue.pop();
        }
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p == nullptr || q == nullptr) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        if (isSameTree(p->left, q->left)) {
            return isSameTree(p->right, q->right);
        }
        return false;
    }
};