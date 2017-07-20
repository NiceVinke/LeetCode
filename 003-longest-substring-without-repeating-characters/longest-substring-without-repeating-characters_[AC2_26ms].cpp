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
        unordered_set<char> st;
        list<char> window;
        while (l < n && r < n) {
            if (!st.count(s[r])) {
                st.insert(s[r++]);
                ans = std::max(ans, r - l);
            } else {
                st.erase(s[l++]);
            }
        }
        return ans;
    }
};
