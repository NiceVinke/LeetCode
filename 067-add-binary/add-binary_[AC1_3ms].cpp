// Given two binary strings, return their sum (also a binary string).
//
//
//
// For example,
// a = "11"
// b = "1"
// Return "100".


class Solution {
public:
    string addBinary(string a, string b)
    {
        if (b.size() > a.size()) return addBinary(b, a);
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        while (j >= 0 || (i >= 0 && carry)) {
            carry += i >= 0 ? a[i--] - '0' : 0;
            carry += j >= 0 ? b[j--] - '0' : 0;
            a[i + 1] = char(carry % 2 + '0');
            carry /= 2;
        }
        return carry ? "1" + a : a;
    }
};
