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
 const auto &node = nodeQueue.front();
 nodeQueue.pop();
 Notice that if using the node after Node queue pop, the address might be invalidated due to the resie process, causing memory access error
 Best way to avoid that is to perform pop operation at the end or not using reference type

 const auto &node = nodeQueue.front();
 ....
 ....
 Do whatever related to node
 ....
 nodeQueue.pop();
 */
#include <queue>
#include <vector>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        std::queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        nodeQueue.push(nullptr); //flag to indicate level
        
        std::vector<int> levelValues;

        while (!nodeQueue.empty()) {
            const auto &node = nodeQueue.front();
            if (node != nullptr) {
                if (node->left) {
                    nodeQueue.push(node->left);
                }
                if (node->right) {
                    nodeQueue.push(node->right);
                }
                levelValues.emplace_back(node->val);
            }
            else {
                result.emplace_back(levelValues);
                if (nodeQueue.size() > 1) {
                    levelValues = std::vector<int>();
                    nodeQueue.push(nullptr);
                }
            }
            nodeQueue.pop();
        }
        return result;
    }
};