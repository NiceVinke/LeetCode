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
public:
    vector<int> largestValues(TreeNode* root)
    {
        vector<int> ans;
        if (!root) return ans;
        queue<TreeNode*> Q;
        Q.push(root);
        int rown = 1, rowmax = INT_MIN;
        TreeNode* tmp = nullptr;
        while (!Q.empty()) {
            int nextrown = 0;
            for (int i = 0; i < rown; ++i) {
                tmp = Q.front();
                if (tmp->val > rowmax)
                    rowmax = tmp->val;
                Q.pop();
                if (tmp->left) {
                    ++nextrown;
                    Q.push(tmp->left);
                }
                if (tmp->right) {
                    ++nextrown;
                    Q.push(tmp->right);
                }
            }
            ans.emplace_back(rowmax);
            rowmax = INT_MIN;
            rown = nextrown;
        }
        return ans;
    }
};
