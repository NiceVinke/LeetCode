// Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
//
// This is case sensitive, for example "Aa" is not considered a palindrome here.
//
// Note:
// Assume the length of given string will not exceed 1,010.
//
//
// Example: 
//
// Input:
// "abccccdd"
//
// Output:
// 7
//
// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.


class Solution {
public:
    int longestPalindrome(string s)
    {
        int ans = 0, odd = 0;
        int alpha[58] = { 0 }; // A ~ z, 65 ~ 122
        for (const auto &c : s) {
            ++alpha[c - 'A'];
        }
        for (const auto &n : alpha) {
            if (n & 1) {
                ans += (n - 1);
                odd = 1;
            } else
                ans += n;
        }
        return ans + odd;
    }
};
