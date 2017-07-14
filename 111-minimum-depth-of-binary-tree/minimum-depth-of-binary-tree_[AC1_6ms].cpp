// Given a binary tree, find its minimum depth.
//
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.


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
    int minDepth(TreeNode* root)
    {
        if (!root) return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int i = 0;
        while (!Q.empty()) {
            ++i;
            int k = Q.size();
            for (int j = 0; j < k; ++j) {
                TreeNode* rt = Q.front();
                if (!rt->left && !rt->right) return i;
                if (rt->left) Q.push(rt->left);
                if (rt->right) Q.push(rt->right);
                Q.pop();
            }
        }
        return -1;
    }
};
