// Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
//
//
//
// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?


class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int ans = 0;
        int mask = 1;
        for (int i = 0; i < 32; ++i, mask <<= 1) {
            int c = 0;
            for (auto& n : nums) if (n & mask) ++c;
            c %= 3;
            if (c) ans |= mask;
        }
        return ans;
    }
};
