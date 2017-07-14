// Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.
//
//
// Note:
//
// All letters in hexadecimal (a-f) must be in lowercase.
// The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
// The given number is guaranteed to fit within the range of a 32-bit signed integer.
// You must not use any method provided by the library which converts/formats the number to hex directly.
//
//
//
// Example 1:
//
// Input:
// 26
//
// Output:
// "1a"
//
//
//
// Example 2:
//
// Input:
// -1
//
// Output:
// "ffffffff"


class Solution {
    const char table[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
public:
    string toHex(int num)
    {
        if (num == 0)
            return "0";
        char arr[9] = { 0 };
        arr[8] = '\0';
        unsigned int tmp = 0xF0000000;
        for (int i = 0; i < 8; ++i)
            arr[i] = table[((tmp >> (i * 4)) & num) >> (28 - i * 4)];
        for (int i = 0; i < 8; ++i) {
            if (arr[i] != '0') {
                return string(arr + i);
            }
        }
    }
};
