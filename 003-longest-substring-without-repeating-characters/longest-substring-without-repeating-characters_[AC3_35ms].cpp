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
        int ans = 0, tmp = 0;
        unordered_map<char, int> m;
        list<char> window;
        for (auto &c : s) {
            if (m[c]) {
                ans = std::max(ans, tmp);
                while (window.front() != c) {
                    --m[window.front()];
                    window.pop_front();
                }
                --m[window.front()];
                window.pop_front();
                ++m[c];
                window.push_back(c);
                tmp = window.size();
            } else {
                ++tmp;
                ++m[c];
                window.push_back(c);
            }
        }
        return std::max(ans, tmp);
    }
};
