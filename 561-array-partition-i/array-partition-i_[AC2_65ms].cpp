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
        int ret = 0;
        int flag = 0;
        array<int, 20001> hashtable{0};
        for(const auto n : nums) {
            ++hashtable[n+10000];
        }
        for (size_t i = 0; i < 20001;) {
            if (hashtable[i] > 0) {
                if (flag == 0) {
                    ret += (i-10000);
                    flag = 1;
                    --hashtable[i];
                } else  {
                    --hashtable[i];
                    flag = 0;
                }
            } else
                ++i;
        }
        return ret;
    }
};
