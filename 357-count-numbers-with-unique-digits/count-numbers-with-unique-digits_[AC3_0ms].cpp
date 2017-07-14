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
        if (n == 0) return 1;
        if (n == 1) return 10;
        vector<int> dp{ 0, 10 };
        pair<int, int> pr{ 9, 9 };
        for (int i = 2; i <= n; ++i) {
            pr.first *= pr.second;
            dp.emplace_back(dp[i - 1] + pr.first);
            if (--pr.second == 0) break;
        }
        return dp.back();
    }
};
