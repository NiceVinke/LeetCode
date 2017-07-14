// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.


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
    TreeNode* helper(vector<int>& nums, int start, int end)
    {
        if (start > end)
            return nullptr;
        else if (start == end)
            return new TreeNode(nums[start]);
        int midIdx = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[midIdx]);
        root->left = helper(nums, start, midIdx - 1);
        root->right = helper(nums, midIdx + 1, end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }
};
