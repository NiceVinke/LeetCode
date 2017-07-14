// Given a positive integer num, write a function which returns True if num is a perfect square else False.
//
//
// Note: Do not use any built-in library function such as sqrt.
//
//
// Example 1:
//
// Input: 16
// Returns: True
//
//
//
// Example 2:
//
// Input: 14
// Returns: False
//
//
//
// Credits:Special thanks to @elmirap for adding this problem and creating all test cases.


class Solution {
public:
    bool isPerfectSquare(int num)
    {
        if (num == 1)
            return true;
        long b = 2, e = num;
        long tmp = 0, m = 0;
        while (b <= e) {
            m = b + (e - b) / 2;
            tmp = m * m;
            if (tmp == num) return true;
            else if (tmp < num) b = m + 1;
            else e = m - 1;
        }
        return false;
    }
};
