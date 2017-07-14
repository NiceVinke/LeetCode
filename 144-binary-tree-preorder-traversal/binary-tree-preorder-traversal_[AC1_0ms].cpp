// Given a binary tree, return the preorder traversal of its nodes' values.
//
//
// For example:
// Given binary tree {1,#,2,3},
//
//    1
//     \
//      2
//     /
//    3
//
//
//
// return [1,2,3].
//
//
// Note: Recursive solution is trivial, could you do it iteratively?


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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *tmp = nullptr;
        while (!s.empty()) {
            tmp = s.top();
            s.pop();
            ans.emplace_back(tmp->val);
            if (tmp->right)
                s.push(tmp->right);
            if (tmp->left)
                s.push(tmp->left);
        }
        return ans;
    }
};
