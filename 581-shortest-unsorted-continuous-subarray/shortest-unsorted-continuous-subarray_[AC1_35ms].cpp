// Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.  
//
// You need to find the shortest such subarray and output its length.
//
// Example 1:
//
// Input: [2, 6, 4, 8, 10, 9, 15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
//
//
//
// Note:
//
// Then length of the input array is in range [1, 10,000].
// The input array may contain duplicates, so ascending order here means <=.


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        int n = nums.size();
        if (n <= 1) return 0;
        int left = 0, right = n - 1;
        while (left < n - 1 && nums[left] <= nums[left + 1]) ++left;
        if (left == n - 1) return 0;
        while (nums[right] >= nums[right - 1]) --right;
        int rmin = INT_MAX, lmax = INT_MIN;
        for (int i = left; i <= right; ++i) {
            if (nums[i] > lmax) lmax = nums[i];
            if (nums[i] < rmin) rmin = nums[i];
        }
        while (left >= 0 && nums[left] > rmin) --left;
        while (right < n && nums[right] < lmax) ++right;
        return right - left - 1;
    }
};
