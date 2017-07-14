// Description:
// Count the number of prime numbers less than a non-negative number, n.
//
// Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.


class Solution {
public:
    int countPrimes(int n)
    {
        if (n <= 2) return 0;
        int ans = n >> 1, m = sqrt(n - 1); // intilize res to n/2, removes all even number(not 2) and 1
        vector<unsigned char> table(n / 8 + 1, 0xff);
        for (int i = 3, j, step; i <= m; i += 2) {
            if (table[i / 8] & (1 << (i % 8))) { // i is an odd prime
                for (step = i * 2, j = i*i; j < n; j += step) { // step=i*2, ignore even numbers
                    if (table[j / 8] & (1 << (j % 8))) {
                        table[j / 8] ^= (1 << (j % 8));
                        --ans;
                    }
                }
            }
        }
        return ans;
    }
};
