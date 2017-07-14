// Given a pattern and a string str, find if str follows the same pattern.
//  Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
//
// Examples:
//
// pattern = "abba", str = "dog cat cat dog" should return true.
// pattern = "abba", str = "dog cat cat fish" should return false.
// pattern = "aaaa", str = "dog cat cat dog" should return false.
// pattern = "abba", str = "dog dog dog dog" should return false.
//
//
//
//
// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
//
//
// Credits:Special thanks to @minglotus6 for adding this problem and creating all test cases.


class Solution {
public:
    bool wordPattern(string pattern, string str)
    {
        stringstream ss(str);
        string s;
        int idx = 0, size = pattern.size();
        unordered_map<char, string> map;
        unordered_set<string> set;

        while (getline(ss, s, ' ') && idx <= size) {
            if (map.find(pattern[idx]) != map.end() && map[pattern[idx]] != s)
                return false;
            if (map.find(pattern[idx]) == map.end() && set.count(s) > 0)
                return false;
            map[pattern[idx++]] = s;
            set.insert(s);
        }
        return idx == size;
    }
};
