// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
//
//
//
// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
//
//
//
//
// The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//
//
// For example,
// Given heights = [2,1,5,6,2,3],
// return 10.


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0, idx = 0;
        stack<int> stk;
        heights.push_back(0);
        while (idx < heights.size()) {
            if (stk.empty() || heights[stk.top()] <= heights[idx]) {
                stk.push(idx++);
            } else {
                int t = stk.top(); stk.pop();
                maxArea = max(maxArea, heights[t] * (stk.empty() ? idx : idx - stk.top() - 1));
            }
        }
        heights.pop_back();
        return maxArea;
    }
};
