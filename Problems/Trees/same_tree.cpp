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
    //DFS
    //Time: O(n)
    //Space: O(n) - worse case
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

    //BFS
    //Time: O(n)
    //Space: O(2**k) - k is the last level of the tree 
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) 
        {
            return true;
        }
         if (p == nullptr || q == nullptr) 
        {
            return false;
        }
        std::queue<TreeNode*> pQueue;
        std::queue<TreeNode*> qQueue;
        
        auto node_check = [](TreeNode* pNode, TreeNode* qNode) -> uint8_t {
            if !(pNode == nullptr && qNode == nullptr) 
            {
                if (pNode == nullptr || qNode == nullptr) 
                {
                    return 0;
                }
                if (pNode->val != qNode->val) 
                {
                    return 0;
                }
                return 2;
            }
            return 1;
        }
        pQueue.emplace(p);
        qQueue.emplace(q);
        while (!pQueue.empty()) {
            auto p = pQueue.front();
            auto q = qQueue.front();
            pQueue.pop();
            qQueue.pop();
            if (p->val != q->val) 
            {
                return false;
            }
            //compare the value of the left with left
            auto check_val = node_check(p->left, q->left);
            if (check_val == 0) {
                return false;
            } else if (check_val == 2) {
                pQueue.emplace(p->left);
                qQueue.emplace(q->left);
            }
            auto check_val = node_check(p->right, q->right);
            if (check_val == 0) {
                return false;
            } else if (check_val == 2) {
                pQueue.emplace(p->right);
                qQueue.emplace(q->right);
            }
        }
        return true;
    }
};