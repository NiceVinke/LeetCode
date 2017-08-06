// Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
//
// Example 1:
//
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Target = 9
//
// Output: True
//
//
//
//
// Example 2:
//
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Target = 28
//
// Output: False


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    void dfs(TreeNode *node, vector<int> &res) {
        if (!node) return;
        dfs(node->left, res);
        res.emplace_back(node->val);
        dfs(node->right, res);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        dfs(root, inorder);
        int l = 0, r = inorder.size() - 1;
        while (l < r) {
            int tmp = inorder[l] + inorder[r];
            if (tmp == k) return true;
            else if (tmp < k) ++l;
            else --r;
        }
        return false;
    }
};
