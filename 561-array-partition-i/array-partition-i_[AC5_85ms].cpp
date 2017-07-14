// Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
//
//
// Example 1:
//
// Input: [1,4,3,2]
//
// Output: 4
// Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
//
//
//
// Note:
//
// n is a positive integer, which is in the range of [1, 10000].
// All the integers in the array will be in the range of [-10000, 10000].


class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int arr[20001] = {0};
        int lim = 10000;
        for (int num: nums)
            ++arr[num + lim];
        int d = 0, sum = 0;
        for (int i = -10000; i <= 10000; ++i) {
            sum += ((arr[i + lim] + 1 - d) >> 1) * i;
            d = (2 + arr[i + lim] - d) % 2;
        }
        return sum;
    }
};
