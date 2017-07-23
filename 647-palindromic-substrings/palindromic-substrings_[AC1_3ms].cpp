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
    // Expend from the current mid point to all of its low and high positions.
    int findPalindromic(string &s, int left, int right, int &n) {
        int count = 0;
        // Increase count if the substring is a validate palindrome.
        while (left >= 0 && right < n && s[left--] == s[right++])
            ++count;
        return count;
    }
public:
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        // Loop across different middle points.
        for (int i = 0; i < n; ++i) {
            // Find all odd length palindrome with i as middle point.
            ans += findPalindromic(s, i, i, n);
            // Find all even length palindrome with i and i+1 as middle point.
            ans += findPalindromic(s, i, i + 1, n);
        }
        return ans;
    }
};
