// Given a binary tree, determine if it is height-balanced.
//
//
//
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


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
    int height(TreeNode *node)
    {
        if (node == nullptr) return 0;
        int hl = height(node->left);
        int hr = height(node->right);
        if (hl == -1 || hr == -1 || abs(hl - hr) > 1) return -1;
        return std::max(hl, hr) + 1;
    }
public:
    bool isBalanced(TreeNode *root)
    {
        return height(root) != -1;
    }
};
