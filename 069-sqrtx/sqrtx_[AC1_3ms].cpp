// Implement int sqrt(int x).
//
// Compute and return the square root of x.


class Solution {
public:
    int mySqrt(int x)
    {
        int ans = 0, bit = 1 << 15; // no need to define as "long"
        while (bit) {
            ans |= bit;
            if (ans > x / ans)
                ans ^= bit;
            bit >>= 1;
        }
        return ans;
    }
};
