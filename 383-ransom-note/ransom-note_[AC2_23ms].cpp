// Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom 
// note can be constructed from the magazines ; otherwise, it will return false. 
//
//
// Each letter in the magazine string can only be used once in your ransom note.
//
//
// Note:
// You may assume that both strings contain only lowercase letters.
//
//
//
// canConstruct("a", "b") -> false
// canConstruct("aa", "ab") -> false
// canConstruct("aa", "aab") -> true


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (magazine.size() < ransomNote.size())
            return false;
        int num[26] = { 0 };
        for (const auto &c : magazine) {
            ++num[c - 'a'];
        }
        for (const auto &c : ransomNote) {
            if (--num[c - 'a'] < 0)
                return false;
        }
        return true;
    }
};
