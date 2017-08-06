// Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
//
// The root is the maximum number in the array. 
// The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
// The right subtree is the maximum tree constructed from right part subarray divided by the maximum number. 
//
//
//
//
// Construct the maximum tree by the given array and output the root node of this tree.
//
//
// Example 1:
//
// Input: [3,2,1,6,0,5]
// Output: return the tree root node representing the following tree:
//
//       6
//     /   \
//    3     5
//     \    / 
//      2  0   
//        \
//         1
//
//
//
// Note:
//
// The size of the given array will be in the range [1,1000].


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
    pair<int, int> findMax(vector<int> &nums, int start, int end) {
        pair<int, int> res(nums[start], start);
        for (; start < end; ++start)
            if (nums[start] > res.first)
                res.first = nums[start], res.second = start;
        return res;
    }
    TreeNode *construct(vector<int> &nums, int start, int end) {
        if (start == end)
            return nullptr;
        auto res = findMax(nums, start, end);
        TreeNode *node = new TreeNode(res.first);
        node->left = construct(nums, start, res.second);
        node->right = construct(nums, res.second + 1, end);
        return node;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size());
    }
};
