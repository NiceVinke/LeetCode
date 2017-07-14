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
        istringstream is(str);
        string tmp;
        vector<string> vs;
        while (is >> tmp)
            vs.push_back(tmp);

        if (pattern.size() != vs.size())
            return false;
        unordered_map<char, string> c2s;
        unordered_map<string, char> s2c;
        for (int i = 0; i < vs.size(); ++i) {
            if (s2c[vs[i]] == 0 && c2s[pattern[i]] == "") {
                s2c[vs[i]] = pattern[i];
                c2s[pattern[i]] = vs[i];
                continue;
            }
            if (s2c[vs[i]] != pattern[i])
                return false;
        }
        return true;
    }
};
