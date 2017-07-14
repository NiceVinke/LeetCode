// Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
//
//
// Example:
//
// Input: The root of a Binary Search Tree like this:
//               5
//             /   \
//            2     13
//
// Output: The root of a Greater Tree like this:
//              18
//             /   \
//           20     13


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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode *cur = root, *prev = nullptr;
        while (cur) {
            if (!cur->right) {
                sum = (cur->val += sum);
                cur = cur->left;
            } else {
                prev = cur->right;
                while (prev->left && prev->left != cur)
                    prev = prev->left;
                if (!prev->left) {
                    prev->left = cur;
                    cur = cur->right;
                } else {
                    prev->left = nullptr;
                    sum = (cur->val += sum);
                    cur = cur->left;
                }
            }
        }
        return root;
    }
};
