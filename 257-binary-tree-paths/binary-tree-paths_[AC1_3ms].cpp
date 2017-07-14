// Given a binary tree, return all root-to-leaf paths.
//
//
// For example, given the following binary tree:
//
//
//
//    1
//  /   \
// 2     3
//  \
//   5
//
//
//
// All root-to-leaf paths are:
// ["1->2->5", "1->3"]
//
//
// Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


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
    void helper(vector<string> &ans, TreeNode *node, string str)
    {
        if (!node->left && !node->right) ans.emplace_back(str + to_string(node->val));
        else {
            if (node->left) helper(ans, node->left, str + to_string(node->val) + "->");
            if (node->right) helper(ans, node->right, str + to_string(node->val) + "->");
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> ans;
        if (!root) return ans;
        helper(ans, root, "");
        return ans;
    }
};
