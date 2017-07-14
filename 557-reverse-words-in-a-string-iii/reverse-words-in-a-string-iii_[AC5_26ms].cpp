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
    string reverseWords(string s) {
        stack<char> stk;
        string revstr(s);
        int cnt = 0;
        for (const auto c : s) {
            if (c == ' ') {
                while (!stk.empty()) {
                    revstr[cnt++] = stk.top();
                    stk.pop();
                }
                revstr[cnt++] = c;
            } else {
                stk.push(c);
            }
        }
        while (!stk.empty()) {
            revstr[cnt++] = stk.top();
            stk.pop();
        }
        return revstr;
    }
};
