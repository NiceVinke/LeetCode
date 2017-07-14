// Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
//
//
// Example:
//
// Input:
//
//    1
//     \
//      3
//     /
//    2
//
// Output:
// 1
//
// Explanation:
// The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
//
//
//
//
// Note:
// There are at least two nodes in this BST.


class Solution {
public:
    void inorderTraverse(TreeNode *node, TreeNode *&prev, int &mindiff)
    {
        if (node->left)
            inorderTraverse(node->left, prev, mindiff);

        if (prev)
            mindiff = min(mindiff, node->val - prev->val);

        prev = node;

        if (node->right)
            inorderTraverse(node->right, prev, mindiff);
    }
    int getMinimumDifference(TreeNode* root)
    {
        int mindiff = INT_MAX;
        TreeNode *prev = nullptr;
        inorderTraverse(root, prev, mindiff);
        return mindiff;
    }
};
