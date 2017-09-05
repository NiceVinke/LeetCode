// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
//
// For example, given the following matrix:
//
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
//
// Return 6.


class Solution {
    int largestRectangleArea(vector<int>& heights, int len) {
        int maxArea = 0, idx = 0;
        stack<int> stk;
        while (idx < len) {
            if (stk.empty() || heights[stk.top()] <= heights[idx]) {
                stk.push(idx++);
            } else {
                int t = stk.top(); stk.pop();
                maxArea = max(maxArea, heights[t] * (stk.empty() ? idx : idx - stk.top() - 1));
            }
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(); if (m == 0) return 0;
        int n = matrix[0].size(); if (n == 0) return 0;
        vector<vector<int>> dp(m, vector<int>(n + 1));
        for (int j = 0; j < n; ++j)
            if (matrix[0][j] == '1')
                dp[0][j] = 1;
        for (int j = 0; j < n; ++j)
            for (int i = 1; i < m; ++i)
                if (matrix[i][j] == '1')
                    dp[i][j] = dp[i - 1][j] + 1;
        int maxArea = 0;
        for (int i = 0; i < m; ++i)
            maxArea = max(maxArea, largestRectangleArea(dp[i], n + 1));
        return maxArea;
    }
};
