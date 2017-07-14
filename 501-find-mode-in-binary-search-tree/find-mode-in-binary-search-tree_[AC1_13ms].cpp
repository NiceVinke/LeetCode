// Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
//
//
// Assume a BST is defined as follows:
//
// The left subtree of a node contains only nodes with keys less than or equal to the node's key.
// The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
// Both the left and right subtrees must also be binary search trees.
//
//
//
//
// For example:
// Given BST [1,null,2,2],
//
//    1
//     \
//      2
//     /
//    2
//
//
//
// return [2].
//
//
// Note:
// If a tree has more than one mode, you can return them in any order.
//
//
// Follow up:
// Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).


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
    void getMaxFreq(TreeNode *node, int &fq, int &pre, int &cnt) {
        if (!node) return;
        getMaxFreq(node->left, fq, pre, cnt);
        if (cnt) node->val == pre ? ++cnt : cnt = 1, pre = node->val;
        else pre = node->val, cnt = 1;
        if (cnt > fq) fq = cnt;
        getMaxFreq(node->right, fq, pre, cnt);
    }
    void getModes(TreeNode *node, int &fq, int &pre, int &cnt, vector<int> &modes) {
        if (!node) return;
        getModes(node->left, fq, pre, cnt, modes);
        if (cnt) node->val == pre ? ++cnt : cnt = 1, pre = node->val;
        else pre = node->val, cnt = 1;
        if (cnt == fq) modes.push_back(node->val);
        getModes(node->right, fq, pre, cnt, modes);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int maxFreq = INT_MIN, pre = 0, cnt = 0;
        getMaxFreq(root, maxFreq, pre, cnt);
        getModes(root, maxFreq, pre, cnt = 0, ans);
        return ans;
    }
};
