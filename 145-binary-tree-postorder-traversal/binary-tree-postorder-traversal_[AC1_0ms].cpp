// Given a binary tree, return the postorder traversal of its nodes' values.
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
// return [3,2,1].
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *tmp = nullptr;
        while (!s.empty()) {
            tmp = s.top();
            s.pop();
            ans.emplace_back(tmp->val);
            if (tmp->left)
                s.push(tmp->left);
            if (tmp->right)
                s.push(tmp->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
