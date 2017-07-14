// Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
//
// For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
//
// Credits:Special thanks to @ts for adding this problem and creating all test cases.


class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        n -= (n >> 1) & 0x55555555; // put count of each 2 bits into those 2 bits
        n = (n & 0x33333333) + (n >> 2 & 0x33333333); // put count of each 4 bits into those 4 bits
        n = (n + (n >> 4)) & 0x0F0F0F0F; // put count of each 8 bits into those 8 bits 
        return n * 0x01010101 >> 24; // returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24)
    }
};
