// Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' operation, the variable x and its coefficient.
//
//
//
// If there is no solution for the equation, return "No solution".
//
//
// If there are infinite solutions for the equation, return "Infinite solutions".
//
//
// If there is exactly one solution for the equation, we ensure that the value of x is an integer.
//
//
// Example 1:
//
// Input: "x+5-3+x=6+x-2"
// Output: "x=2"
//
//
//
// Example 2:
//
// Input: "x=x"
// Output: "Infinite solutions"
//
//
//
// Example 3:
//
// Input: "2x=x"
// Output: "x=0"
//
//
//
// Example 4:
//
// Input: "2x+3x-6x=x+2"
// Output: "x=-1"
//
//
//
// Example 5:
//
// Input: "x=x+2"
// Output: "No solution"


class Solution {
    void calcu(string &str, int &xnum, int& num) {
        string tmp;
        for (auto it = str.begin(); it != str.end(); ++it) {
            if (it == str.begin() && *it == '-')
                tmp.push_back(*it);
            else {
                if (*it != '+' && *it != '-' && *it != '.')
                    tmp.push_back(*it);
                else {
                    if (tmp.back() == 'x') {
                        if (tmp.size() == 1) ++xnum;
                        else if (tmp == "-x") --xnum;
                        else xnum += stoi(tmp.substr(0, tmp.size() - 1));
                    } else
                        num += stoi(tmp);
                    tmp.clear();
                    if (*it != '+')
                        tmp.push_back(*it);
                }
            }
        }
    }
public:
    string solveEquation(string equation) {
        string left(equation.substr(0, equation.find('=')) + '.'),
            right(equation.substr(equation.find('=') + 1) + '.');

        string ans;
        int nans = 0;
        int lxnum = 0, rxnum = 0, lnum = 0, rnum = 0;
        calcu(left, lxnum, lnum);
        calcu(right, rxnum, rnum);

        rnum -= lnum;
        lxnum -= rxnum;
        if (rnum == 0 && lxnum == 0)
            ans = "Infinite solutions";
        else if (lxnum == 0)
            ans = "No solution";
        else
            ans = "x=" + to_string(rnum / lxnum);
        return ans;
    }
};
