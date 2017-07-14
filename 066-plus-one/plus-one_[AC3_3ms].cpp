// Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
//
// You may assume the integer do not contain any leading zero, except the number 0 itself.
//
// The digits are stored such that the most significant digit is at the head of the list.


class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        for (const auto &d : digits) {
            if (d != 9) {
                int last = digits.size() - 1;
                ++digits[last];
                while (digits[last] > 9) {
                    digits[last] -= 10;
                    ++digits[--last];
                }
                return digits;
            }
        }
        vector<int> ans(digits.size() + 1);
        ans[0] = 1;
        return ans;
    }
};
