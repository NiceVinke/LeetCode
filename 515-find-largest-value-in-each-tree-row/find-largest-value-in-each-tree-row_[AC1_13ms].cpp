// You need to find the largest value in each row of a binary tree.
//
// Example:
//
// Input: 
//
//           1
//          / \
//         3   2
//        / \   \  
//       5   3   9 
//
// Output: [1, 3, 9]


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
    void dfs(const TreeNode* node, const int depth, vector<int>& ans)
    {
        if (!node) return;
        if (ans.size() <= depth) ans.emplace_back(node->val);
        else ans[depth] = std::max(ans[depth], node->val);
        dfs(node->left, depth + 1, ans);
        dfs(node->right, depth + 1, ans);
    }
public:
    vector<int> largestValues(TreeNode* root)
    {
        vector<int> ans;
        if (root) dfs(root, 0, ans);
        return ans;
    }
};
