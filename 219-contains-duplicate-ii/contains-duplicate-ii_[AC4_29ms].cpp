// Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m[nums[i]] && i - m[nums[i]] < k) {
                return true;
            } else {
                m[nums[i]] = i + 1; //防止default值造成的困惑
            }
        }
        return false;
    }
};
