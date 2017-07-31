// Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them. 
//
//
// Two trees are duplicate if they have the same structure with same node values.
//
//
// Example 1: 
//
//         1
//        / \
//       2   3
//      /   / \
//     4   2   4
//        /
//       4
//
// The following are two duplicate subtrees:
//
//       2
//      /
//     4
//
// and
//
//     4
//
// Therefore, you need to return above trees' root in the form of a list.


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
    string helper(TreeNode *&node,
        unordered_map<string, vector<TreeNode*>> &m) {
        string str = to_string(node->val);
        str += node->left ? "-l>" + helper(node->left, m) : "noleft";
        str += node->right ? "-r>" + helper(node->right, m) : "noright";
        m[str].push_back(node);
        return str;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> m;
        vector<TreeNode*> ans;
        if (root) helper(root, m);
        for (const auto &pr : m) {
            if (pr.second.size() > 1)
                ans.push_back(pr.second[0]);
        }
        return ans;
    }
};
