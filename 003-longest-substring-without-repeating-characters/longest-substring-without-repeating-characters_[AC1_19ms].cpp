// Given a string, find the length of the longest substring without repeating characters.
//
// Examples:
//
// Given "abcabcbb", the answer is "abc", which the length is 3.
//
// Given "bbbbb", the answer is "b", with the length of 1.
//
// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n < 2) return n;
        int ans = 0, l = 0, r = 0;
        unordered_map<char, int> hashmap;
        for (; r < n; ++r) {
            if (hashmap.count(s[r]))
                l = std::max(l, hashmap[s[r]]);
            ans = std::max(ans, r - l + 1);
            hashmap[s[r]] = r + 1;
        }
        return ans;
    }
};
