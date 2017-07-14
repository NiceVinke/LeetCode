// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
//
// Examples:
//
// s = "leetcode"
// return 0.
//
// s = "loveleetcode",
// return 2.
//
//
//
//
// Note: You may assume the string contain only lowercase letters.


class Solution {
public:
    int firstUniqChar(string s)
    {
        pair<int, int> counts[128];
        for (int i = 0; i < s.size(); ++i) {
            ++counts[s[i]].first;
            counts[s[i]].second = i;
        }
        int idx = s.size();
        for (int i = 'a'; i <= 'z'; ++i) {
            if (counts[i].first == 1)
                idx = min(idx, counts[i].second);
        }
        return idx == s.size() ? -1 : idx;
    }
};
