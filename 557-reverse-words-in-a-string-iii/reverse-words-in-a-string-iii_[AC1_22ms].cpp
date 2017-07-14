// Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
//
// Example 1:
//
// Input: "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
//
//
//
// Note:
// In the string, each word is separated by single space and there will not be any extra space in the string.


class Solution {
public:
    void myReverse(char *a, char *b) {
        while (a < b) {
            *a ^= *b ^= *a ^= *b;
            ++a;
            --b;
        }
    }
    string reverseWords(string s) {
        int i = 0, j = 0;
        for (i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                myReverse(&s[j], &s[i - 1]);
                j = i + 1;
            }
        }
        myReverse(&s[j], &s[i - 1]);
        
        return s;
    }
};
