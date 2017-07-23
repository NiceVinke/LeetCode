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
    int isPalindromic(string &s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--])
                return 0;
        }
        return 1;
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = n;
        for (int chs = 1; chs < n; ++chs) {
            for (int start = 0; start < n - chs; ++start) {
                ans += isPalindromic(s, start, start + chs);
        	}
        }
        return ans;
    }
};
