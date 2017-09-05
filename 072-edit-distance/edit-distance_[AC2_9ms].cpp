// Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
//
//
//
// You have the following 3 operations permitted on a word:
//
//
//
// a) Insert a character
// b) Delete a character
// c) Replace a character


class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> dp(n + 1);
        for (int i = 0; i <= m; ++i) {
            int last = 0;
            for (int j = 0; j <= n; ++j) {
                if (i == 0) {
                    dp[j] = j;
                } else if (j == 0) {
                    last = dp[j];
                    dp[j] = i;
                } else {
                    int tmp = dp[j];
                    dp[j] = min(last + (word1[i - 1] == word2[j - 1] ? 0 : 1),
                                   min(dp[j] + 1, dp[j - 1] + 1));
                    last = tmp;
                }
            }
        }
        return dp[n];
    }
};
