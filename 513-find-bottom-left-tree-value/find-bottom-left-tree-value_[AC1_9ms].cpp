// Given a binary tree, find the leftmost value in the last row of the tree. 
//
//
// Example 1:
//
// Input:
//
//     2
//    / \
//   1   3
//
// Output:
// 1
//
//
//
//   Example 2: 
//
// Input:
//
//         1
//        / \
//       2   3
//      /   / \
//     4   5   6
//        /
//       7
//
// Output:
// 7
//
//
//
// Note:
// You may assume the tree (i.e., the given root node) is not NULL.


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
    void helper(TreeNode *node, int curLevel, int &maxLevel, int &ans) {
        if (!node) return;
        if (curLevel > maxLevel) maxLevel = curLevel, ans = node->val;
        helper(node->left, curLevel + 1, maxLevel, ans);
        helper(node->right, curLevel + 1, maxLevel, ans);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0, level = INT_MIN;
        helper(root, 0, level, ans);
        return ans;
    }
};
