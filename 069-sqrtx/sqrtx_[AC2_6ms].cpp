// Implement int sqrt(int x).
//
// Compute and return the square root of x.


class Solution {
public:
    int mySqrt(int x)
    {
        if (x < 0) return -1;
        if (x < 2) return x;
        int low = 1, high = x;
        int mid = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (mid <= x / mid && mid > (x / (mid + 1) - 1))
                return mid;
            else if (mid <= (x / (mid + 1) - 1))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return 0;
    }
};
