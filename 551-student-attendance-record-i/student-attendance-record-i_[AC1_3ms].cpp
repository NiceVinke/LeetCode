// You are given a string representing an attendance record for a student. The record only contains the following three characters:
//
//
//
// 'A' : Absent. 
// 'L' : Late.
//  'P' : Present. 
//
//
//
//
// A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).    
//
// You need to return whether the student could be rewarded according to his attendance record.
//
// Example 1:
//
// Input: "PPALLP"
// Output: True
//
//
//
// Example 2:
//
// Input: "PPALLL"
// Output: False


class Solution {
public:
    bool checkRecord(string s)
    {
        int nA = 0, nL = 0;
        for (const auto c : s) {
            if (c != 'L') {
                nL = 0;
                if (c == 'A')
                    ++nA;
            } else
                ++nL;

            if (nA > 1 || nL > 2)
                return false;
        }
        return true;
    }
};
