// Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below. 
//
//
//
//
//
//
//
// Example 1:
//
// Input: ["Hello", "Alaska", "Dad", "Peace"]
// Output: ["Alaska", "Dad"]
//
//
//
// Note:
//
// You may use one character in the keyboard more than once.
// You may assume the input string will only contain letters of alphabet.


class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        const int whichRow[26] = {
            1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2
        };
        vector<string> rtn;
        int r = 0;
        for (const auto s : words) {
            r = whichRow[tolower(s[0]) - 'a'];
            auto it = s.cbegin();
            for (; it != s.cend(); ++it) {
                if (r != whichRow[tolower(*it) - 'a'])
                    break;
            }
            if (it == s.cend())
                rtn.push_back(s);
        }
        return rtn;
    }
};
