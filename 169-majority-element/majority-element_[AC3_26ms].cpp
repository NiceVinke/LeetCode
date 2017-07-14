// Given an array of size n, find the majority element. The majority element is the element that appears more than &lfloor; n/2 &rfloor; times.
//
// You may assume that the array is non-empty and the majority element always exist in the array.
//
// Credits:Special thanks to @ts for adding this problem and creating all test cases.


class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        unordered_map<int, int> counts;
        int maj = nums.size() >> 1;
        for (const auto &n : nums)
            if (++counts[n] > maj)
                return n;
        return 0;
    }
};
