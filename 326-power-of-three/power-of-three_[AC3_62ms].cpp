// Given an integer, write a function to determine if it is a power of three.
//
//
//     Follow up:
//     Could you do it without using any loop / recursion?
//
//
// Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.


class Solution {
public:
    bool isPowerOfThree(int n)
    {
        if (n == 1)
            return true;

        for (int tmp = 0; n > 1; tmp = 0, n /= 3) {
            string str(to_string(n));
            for (const auto &c : str)
                tmp += c - '0';
            if (tmp % 3)
                return false;
        }
        return n == 1;
    }
};
