// Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
//
// You may assume the integer do not contain any leading zero, except the number 0 itself.
//
// The digits are stored such that the most significant digit is at the head of the list.


class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        for (int i = digits.size(); i--; digits[i] = 0)
            if (digits[i]++ < 9)
                return digits;
        digits[0]++;
        digits.push_back(0);
        return digits;
    }
};
