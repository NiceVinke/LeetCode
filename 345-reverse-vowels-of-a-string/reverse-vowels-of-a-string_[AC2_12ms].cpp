// Write a function that takes a string as input and reverse only the vowels of a string.
//
//
// Example 1:
// Given s = "hello", return "holle".
//
//
//
// Example 2:
// Given s = "leetcode", return "leotcede".
//
//
//
// Note:
// The vowels does not include the letter "y".


class Solution {
public:
    string reverseVowels(string s)
    {
        string Vowels("aeiouAEIOU");
        int b = 0, e = s.size() - 1;
        while (b < e) {
            b = s.find_first_of(Vowels, b);
            e = s.find_last_of(Vowels, e);
            if (b < e) swap(s[b++], s[e--]);
        }
        return s;
    }
};
