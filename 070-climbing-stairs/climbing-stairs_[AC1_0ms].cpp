// You are climbing a stair case. It takes n steps to reach to the top.
//
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//
//
// Note: Given n will be a positive integer.


class Solution {
public:
    int climbStairs(int n)
    {
        if (n <= 3)
            return n;

        int point_1 = 2;
        int point_2 = 1;
        int ans = 0;

        for (int i = 2; i < n; ++i) {
            ans = point_1 + point_2;
            point_2 = point_1;
            point_1 = ans;
        }
        return ans;
    }
};
