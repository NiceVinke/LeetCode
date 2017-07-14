// Given an index k, return the kth row of the Pascal's triangle.
//
//
// For example, given k = 3,
// Return [1,3,3,1].
//
//
//
// Note:
// Could you optimize your algorithm to use only O(k) extra space?


class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans(rowIndex + 1, 1);
        for (int row = 1; row < rowIndex; ++row)
            for (int col = row; col > 0; --col)
                ans[col] += ans[col - 1];
        return ans;
    }
};
