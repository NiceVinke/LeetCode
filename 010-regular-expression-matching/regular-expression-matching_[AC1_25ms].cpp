// Implement regular expression matching with support for '.' and '*'.
//
//
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
//
// The matching should cover the entire input string (not partial).
//
// The function prototype should be:
// bool isMatch(const char *s, const char *p)
//
// Some examples:
// isMatch("aa","a") &rarr; false
// isMatch("aa","aa") &rarr; true
// isMatch("aaa","aa") &rarr; false
// isMatch("aa", "a*") &rarr; true
// isMatch("aa", ".*") &rarr; true
// isMatch("ab", ".*") &rarr; true
// isMatch("aab", "c*a*b") &rarr; true


class Solution {
    bool matchCore(const char *str, const char *pattern) {
        if (*str == '\0' && *pattern == '\0') return true;
        if (*str != '\0' && *pattern == '\0') return false;
        if (*(pattern + 1) == '*') {
            if (*str == *pattern || (*pattern == '.' && *str != '\0'))
                return matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
            else
                return matchCore(str, pattern + 2);
        }
        if (*str == *pattern || (*pattern == '.' && *str != '\0'))
            return matchCore(str + 1, pattern + 1);
        return false;
    }
public:
    bool isMatch(string s, string p) {
        if (p == ".*") return true;
        return matchCore(s.c_str(), p.c_str());
    }
};
