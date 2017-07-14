// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//
// You may assume no duplicates in the array.
//
//
// Here are few examples.
// [1,3,5,6], 5 &#8594; 2
// [1,3,5,6], 2 &#8594; 1
// [1,3,5,6], 7 &#8594; 4
// [1,3,5,6], 0 &#8594; 0


class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        if (target < nums[0])
            return 0;
        if (nums[nums.size() - 1] < target)
            return nums.size();

        int first = 0, last = nums.size(), mid = 0;
        while (first < last) {
            mid = first + ((last - first) >> 1);
            if (nums[mid] < target)
                first = mid + 1;
            else
                last = mid;
        }
        return first;
    }
};
