// Write a function that takes a string as input and returns the string reversed.
//
//
// Example:
// Given s = "hello", return "olleh".


class Solution {
public:
    string reverseString(string s) {
        char *a = &s[0];
        char *b = &s[s.size() - 1];
        while (a < b) {
            *a ^= *b ^= *a ^= *b;
            ++a;
            --b;
        }
        return s;
    }
};
