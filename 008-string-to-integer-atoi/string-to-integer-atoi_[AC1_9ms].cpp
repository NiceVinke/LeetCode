// Implement atoi to convert a string to an integer.
//
// Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
//
//
// Notes: 
// It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front. 
//
//
// Update (2015-02-10):
// The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
//
//
// spoilers alert... click to show requirements for atoi.
//
// Requirements for atoi:
//
// The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
//
// The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
//
// If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
//
// If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.


class Solution {
public:
    int myAtoi(string str) {
        long base = 0;
        int pos = 1;
        for (int i = 0; i < str.size();) {
            i = str.find_first_not_of(' ');
            if (str[i] == '-' || str[i] == '+')
                pos = (str[i++] == '-') ? -1 : 1;
            while (isdigit(str[i])) {
                base = base * 10 + (str[i++] - '0');
                if (base * pos >= INT_MAX) return INT_MAX;
                if (base * pos <= INT_MIN) return INT_MIN;
            }
            return base * pos;
        }
        return base * pos;
    }
};
