// Given an integer, return its base 7 string representation.
//
// Example 1:
//
// Input: 100
// Output: "202"
//
//
//
// Example 2:
//
// Input: -7
// Output: "-10"
//
//
//
// Note:
// The input will be in range of [-1e7, 1e7].


class Solution {
public:
    string convertToBase7(int num)
    {
        string ans;
        int n = abs(num);
        do {
            ans = to_string(n % 7) + ans;
            n /= 7;
        } while (n);
        return num < 0 ? "-" + ans : ans;
    }
};
