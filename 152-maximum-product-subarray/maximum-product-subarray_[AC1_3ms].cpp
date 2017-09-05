// Find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
//
//
// For example, given the array [2,3,-2,4],
// the contiguous subarray [2,3] has the largest product = 6.


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int res = nums[0], tmax = res, tmin = res;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < 0) swap(tmax, tmin);
            tmax = max(nums[i], nums[i] * tmax);
            tmin = min(nums[i], nums[i] * tmin);
            res = max(res, tmax);
        }
        return res;
    }
};
