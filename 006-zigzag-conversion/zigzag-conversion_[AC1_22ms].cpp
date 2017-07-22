// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
// P   A   H   N
// A P L S I I G
// Y   I   R
//
//
// And then read line by line: "PAHNAPLSIIGYIR"
//
//
// Write the code that will take a string and make this conversion given a number of rows:
//
// string convert(string text, int nRows);
//
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2) return s;
        vector<string> zigzag(numRows);
        int Cnt = 0;
        bool inc = true;
        for (const auto &c : s) {
            zigzag[Cnt].push_back(c);
            if (Cnt == 0)
                inc = true;
            else if (Cnt == numRows - 1)
                inc = false;
            if (inc)
                ++Cnt;
            else
                --Cnt;
        }
        for (auto i = 1; i < numRows; ++i)
            zigzag[0] += zigzag[i];

        return zigzag[0];
    }
};
