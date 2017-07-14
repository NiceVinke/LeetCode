// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
//
//
// return its bottom-up level order traversal as:
//
// [
//   [15,7],
//   [9,20],
//   [3]
// ]


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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        if (!root)
            return{};

        vector<vector<int>> ans;
        vector<int> level;
        queue<TreeNode *> q;
        TreeNode *tmp = nullptr;
        int cnt = 1, curCnt = 0;
        q.push(root);
        while (!q.empty()) {
            level.clear();
            curCnt = 0;
            while (cnt--) {
                tmp = q.front();
                level.emplace_back(tmp->val);
                q.pop();
                if (tmp->left) {
                    q.push(tmp->left);
                    ++curCnt;
                }
                if (tmp->right) {
                    q.push(tmp->right);
                    ++curCnt;
                }
            }
            cnt = curCnt;
            ans.push_back(level);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
