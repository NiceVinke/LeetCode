// Given two arrays, write a function to compute their intersection.
//
//
// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
//
//
// Note:
//
// Each element in the result must be unique.
// The result can be in any order.


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans;
        unordered_set<int> interSet(nums1.begin(), nums1.end());
        for (const auto &n : nums2) {
            if (interSet.erase(n)) {
                ans.emplace_back(n);
            }
        }
        return ans;
    }
};
