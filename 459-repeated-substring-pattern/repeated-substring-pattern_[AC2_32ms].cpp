// Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.  You may assume the given string consists of lowercase English letters only and its length  will not exceed 10000. 
//
// Example 1:
//
// Input: "abab"
//
// Output: True
//
// Explanation: It's the substring "ab" twice.
//
//
//
// Example 2:
//
// Input: "aba"
//
// Output: False
//
//
//
// Example 3:
//
// Input: "abcabcabcabc"
//
// Output: True
//
// Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)


class Solution {
public:
    bool repeatedSubstringPattern(string str)
    {
        int k = -1, m = str.size();
        vector<int> p(m + 1, -1);
        for (int i = 1; i <= m; ++i) {
            while (k >= 0 && str[k] != str[i - 1]) k = p[k];
            p[i] = ++k;
        }
        return p[m] && (p[m] % (m - p[m]) == 0);
    }
};
