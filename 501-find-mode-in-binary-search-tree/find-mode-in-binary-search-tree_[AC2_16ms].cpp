// Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
//
//
// Assume a BST is defined as follows:
//
// The left subtree of a node contains only nodes with keys less than or equal to the node's key.
// The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
// Both the left and right subtrees must also be binary search trees.
//
//
//
//
// For example:
// Given BST [1,null,2,2],
//
//    1
//     \
//      2
//     /
//    2
//
//
//
// return [2].
//
//
// Note:
// If a tree has more than one mode, you can return them in any order.
//
//
// Follow up:
// Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).


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
    vector<int> modes;
    
    vector<int> findMode(TreeNode* r) {
      int mfq/*max freq*/, pre/*previous val*/, cnt/*duplicates count*/;
      getMaxFreq(r, mfq=0, pre, cnt=0); // in-order traversal to get max frequency
      getMode(r, mfq, pre, cnt=0);      // in-order traversal to get all modes
      return modes;
    }
    
    void getMaxFreq(TreeNode* r, int& mfq, int& pre, int& cnt) {
      if (!r) return;
      getMaxFreq(r->left, mfq, pre, cnt);
      getMaxFreq(r->right, mfq=max(mfq,cnt), pre=r->val, ++(cnt*=(r->val==pre)));
    }
    
    void getMode(TreeNode* r, const int mfq, int& pre, int& cnt) {
      if (!r) return;
      getMode(r->left, mfq, pre, cnt);
      if (mfq == ++(cnt*=(r->val==pre))) modes.push_back(r->val);
      getMode(r->right, mfq, pre=r->val, cnt);
    }
};
