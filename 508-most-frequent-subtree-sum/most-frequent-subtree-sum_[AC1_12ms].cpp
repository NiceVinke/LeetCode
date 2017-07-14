// Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.
//
//
// Examples 1
// Input:
//
//   5
//  /  \
// 2   -3
//
// return [2, -3, 4], since all the values happen only once, return all of them in any order.
//
//
// Examples 2
// Input:
//
//   5
//  /  \
// 2   -5
//
// return [2], since 2 happens twice, however -5 only occur once.
//
//
// Note:
// You may assume the sum of values in any subtree is in the range of 32-bit signed integer.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int helper(TreeNode *node, unordered_map<int, int> &m, int &maxV, vector<int> &ans) {
        if (!node) return 0;
        int s = node->val + (helper(node->left, m, maxV, ans)) + (helper(node->right, m, maxV, ans));
        int t = ++m[s];
        if (t > maxV) {
            maxV = t;
            ans.clear();
            ans.emplace_back(s);
        } else if (t == maxV)
            ans.emplace_back(s);
        return s;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> m;
        vector<int> ans;
        int maxV = INT_MIN;
        helper(root, m, maxV, ans);
        return ans;
    }
};
