/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
#include <deque>
#include <queue>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
/*
Experiment using vector, deque, and queue to solve
deque or vector will be more efficient?

Tested with leetcode, deque solution is the most efficient in terms of time and space
incomparison to vector or queue

Observing that Solution4 which uses no data structure and the solution is simpler run slower
on leetcode, yet is the most efficient in space.

std::move() also help reducing runtime
*/
//Vector
class Solution1 {
public:
    std::vector<TreeNode*> retrieveAncestors(TreeNode *root, TreeNode* target) {
        std::vector<TreeNode*> ancestors;
        if (root == nullptr || target == nullptr){
            return ancestors;
        }
        if (root == target) {
            ancestors.emplace_back(root);
            return ancestors;
        }
        if (target->val < root->val) {
            ancestors = retrieveAncestors(root->left, target);
        } else {
            ancestors = retrieveAncestors(root->right, target);
        }
        ancestors.emplace_back(root);
        return std::move(ancestors);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto pAncestors = retrieveAncestors(root, p);
        auto qAncestors = retrieveAncestors(root, q);
        auto lowestAncestor = root;
        auto pReversedIterator = pAncestors.rbegin();
        auto qReversedIterator = qAncestors.rbegin();
        while (pReversedIterator != pAncestors.rend() && 
            qReversedIterator != qAncestors.rend()) {
                if (*pReversedIterator == *qReversedIterator) {
                    lowestAncestor = *pReversedIterator;
                    pReversedIterator++;
                    qReversedIterator++;
                } else {
                    break;
                }
        }
        return lowestAncestor;
    }
};

//Deque
class Solution2 {
public:
    std::deque<TreeNode*> retrieveAncestors(TreeNode *root, TreeNode* target) {
        std::deque<TreeNode*> ancestors;
        if (root == nullptr || target == nullptr){
            return ancestors;
        }
        if (root == target) {
            ancestors.push_front(root);
            return ancestors;
        }
        if (target->val < root->val) {
            ancestors = retrieveAncestors(root->left, target);
        } else {
            ancestors = retrieveAncestors(root->right, target);
        }
        ancestors.push_front(root);
        return std::move(ancestors);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto pAncestors = retrieveAncestors(root, p);
        auto qAncestors = retrieveAncestors(root, q);
        auto lowestAncestor = root;
        while (!pAncestors.empty() &&  !qAncestors.empty()) {
                if (pAncestors.front() == qAncestors.front()) {
                    lowestAncestor = pAncestors.front();
                    pAncestors.pop_front();
                    qAncestors.pop_front();
                } else {
                    break;
                }
        }
        return lowestAncestor;
    }
};

//Queue
class Solution3 {
public:
    std::queue<TreeNode*> retrieveAncestors(TreeNode *root, TreeNode* target) {
        std::queue<TreeNode*> ancestors;
        if (root == nullptr || target == nullptr){
            return ancestors;
        }
        if (root == target) {
            ancestors.push(root);
            return ancestors;
        }
        if (target->val < root->val) {
            ancestors = retrieveAncestors(root->left, target);
        } else {
            ancestors = retrieveAncestors(root->right, target);
        }
        ancestors.push(root);
        return ancestors;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto pAncestors = retrieveAncestors(root, p);
        auto qAncestors = retrieveAncestors(root, q);
        auto startQueue = pAncestors;
        while (pAncestors.size() > qAncestors.size()) {
            pAncestors.pop();
        }
        while (pAncestors.size() < qAncestors.size()) {
            qAncestors.pop();
        }
        while (pAncestors.front() != qAncestors.front()) {
                pAncestors.pop();
                qAncestors.pop();
        }
        return pAncestors.front();
    }
};

//Queue
class Solution4 {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto commonRoot = root;

        while (commonRoot) {
            if (p->val < commonRoot->val && q->val < commonRoot->val) {
                commonRoot = commonRoot->left;
            }
            else if (p->val > commonRoot->val && q->val > commonRoot->val) {
                commonRoot = commonRoot->right;
            }
            else {
                return commonRoot
            }
        }
        return commonRoot;
    }
};