// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
//
// Note:
//
// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.


class Solution {
public:
    string addStrings(string num1, string num2)
    {
        if (num2.size() > num1.size())
            return addStrings(num2, num1);

        int carry = 0, i = num1.size() - 1, j = num2.size() - 1;

        for (; i >= 0 && (carry || j >= 0); --i, --j, carry /= 10)
            num1[i] = (carry += ((num1[i] - '0') + (j >= 0 ? (num2[j] - '0') : 0))) % 10 + '0';

        return (carry ? "1" : "") + num1;
    }
};
