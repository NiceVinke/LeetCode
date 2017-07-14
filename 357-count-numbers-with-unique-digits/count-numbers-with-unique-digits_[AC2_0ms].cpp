// Given a non-negative integer n, count all numbers with unique digits, x, where 0 &le; x &lt; 10n.
//
//
//     Example:
// Given n = 2, return 91. (The answer should be the total numbers in the range of 0 &le; x &lt; 100, excluding [11,22,33,44,55,66,77,88,99])
//
//
// Credits:Special thanks to @memoryless for adding this problem and creating all test cases.


class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (!n) return 1;
        int ans = 10, cur = 9, avail = 9;
        while (--n && avail) ans += (cur *= (avail--));
        return ans;
    }
};
