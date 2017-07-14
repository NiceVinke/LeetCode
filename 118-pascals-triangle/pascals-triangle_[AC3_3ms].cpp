// Given numRows, generate the first numRows of Pascal's triangle.
//
//
// For example, given numRows = 5,
// Return
//
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]


class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows < 1) return{};
        if (numRows == 1) return{ {1} };
        if (numRows == 2) return{ {1}, {1,1} };
        vector<vector<int>> ans;
        ans.push_back(vector<int>(1, 1));
        ans.push_back(vector<int>(2, 1));
        for (int i = 2; i < numRows; ++i) {
            ans.push_back(vector<int>(i + 1, 1));
            for (int j = 0; j < i - 1; ++j) {
                ans[i][j + 1] = ans[i - 1][j] + ans[i - 1][j + 1];
            }
        }
        return ans;
    }
};
