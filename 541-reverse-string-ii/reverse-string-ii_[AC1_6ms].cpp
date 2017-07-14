// Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
//
//
// Example:
//
// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"
//
//
//
// Restrictions: 
//
//  The string consists of lower English letters only.
//  Length of the given string and k will in the range [1, 10000]


class Solution {
public:
    void myReverse(char *a, char *b) {
        while (a < b) {
            *a ^= *b ^= *a ^= *b;
            ++a;
            --b;
        }
    }
    string reverseStr(string s, int k) {
        int i = 0, j = 0;
        for (i = 0; i < s.size(); i += 2*k) {
            myReverse(&s[i], min(&s[i + k - 1], &s[s.size() - 1]));
        }
        
        return s;
    }
};
