// Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        int n = nums.size();
        if (k <= 0 || n < 2)
            return false;
        unordered_set<int> s;
        for (int i = 0; i < n; ++i) {
            if (i > k)
                s.erase(nums[i - k - 1]);
            if (!s.insert(nums[i]).second)
                return true;
        }
        return false;
    }
};
