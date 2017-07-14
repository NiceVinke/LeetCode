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
        // 3^19 = 1162261467, 3^20 = 3486784401 > INT_MAX
        return n > 0 ? (1162261467 / n == 1162261467 / (double)n) : false;
    }
};
