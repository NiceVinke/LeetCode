// Write a program that outputs the string representation of numbers from 1 to n.
//
// But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.
//
// Example:
//
// n = 15,
//
// Return:
// [
//     "1",
//     "2",
//     "Fizz",
//     "4",
//     "Buzz",
//     "Fizz",
//     "7",
//     "8",
//     "Fizz",
//     "Buzz",
//     "11",
//     "Fizz",
//     "13",
//     "14",
//     "FizzBuzz"
// ]


class Solution {
public:
    vector<string> fizzBuzz(int n) {
        int m = 0;
        int c3 = 0;
        int c5 = 0;
        vector<string> rtn(n);
        while (m < n) {
            if (++c3 == 3) {
                c3 = 0;
                rtn[m] = "Fizz";
            }
            if (++c5 == 5) {
                c5 = 0;
                rtn[m] += "Buzz";
            }
            if (rtn[m].empty())
                rtn[m] = to_string(m + 1);
            ++m;
        }
        return rtn;
    }
};
