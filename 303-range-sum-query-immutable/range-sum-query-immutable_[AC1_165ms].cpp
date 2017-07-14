// Given an integer array nums, find the sum of the elements between indices i and j (i &le; j), inclusive.
//
// Example:
//
// Given nums = [-2, 0, 3, -5, 2, -1]
//
// sumRange(0, 2) -> 1
// sumRange(2, 5) -> -1
// sumRange(0, 5) -> -3
//
//
//
// Note:
//
// You may assume that the array does not change.
// There are many calls to sumRange function.


class NumArray {
    vector<int> part;
public:
    NumArray(vector<int> nums) : part(nums.size() + 1)
    {
        partial_sum(nums.begin(), nums.end(), part.begin() + 1);
    }

    int sumRange(int i, int j) const
    {
        return part[j + 1] - part[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
