// Given a string, your task is to count how many palindromic substrings in this string.
//
//
//
// The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters. 
//
//
// Example 1:
//
// Input: "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
//
//
//
// Example 2:
//
// Input: "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
//
//
//
// Note:
//
// The input string length won't exceed 1000.


class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        vector<vector<char>> isp(n, vector<char>(n, false));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                ans += isp[i][j] = i == j || s[i] == s[j] && (i + 1 == j || isp[i + 1][j - 1]);
            }
        }
        return ans;
    }
};
