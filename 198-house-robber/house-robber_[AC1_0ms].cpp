// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
// Credits:Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.


class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int even = nums[0], odd = 0;
        for (int i = 1; i < n; ++i) {
            if (i & 1) odd = std::max(odd + nums[i], even);
            else even = std::max(even + nums[i], odd);
        }
        return std::max(even, odd);
    }
};
