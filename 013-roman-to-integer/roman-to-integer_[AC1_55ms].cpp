// Given a roman numeral, convert it to an integer.
//
// Input is guaranteed to be within the range from 1 to 3999.


class Solution {
public:
    int romanToInt(string s)
    {
        int roman[128] = { 0 };
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        int n = s.size() - 1;
        int ans = roman[s[n]];

        while (n--)
            ans += roman[s[n]] < roman[s[n + 1]] ? -roman[s[n]] : roman[s[n]];

        return ans;
    }
};
