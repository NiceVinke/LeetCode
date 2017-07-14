// Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list. 
//
// Example 1:
//
// Input: ["23:59","00:00"]
// Output: 1
//
//
//
// Note:
//
// The number of time points in the given list is at least 2 and won't exceed 20000.
// The input time is legal and ranges from 00:00 to 23:59.


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        sort(timePoints.begin(), timePoints.end());
        auto diff = [](string &t1, string &t2) {
            return (((t2[0] - t1[0]) * 10 + (t2[1] - t1[1])) * 60) + ((t2[3] - t1[3]) * 10 + (t2[4] - t1[4]));
        };
        int ans = INT_MAX;
        for (int i = 1; i < n; ++i)
            ans = std::min(ans, diff(timePoints[i - 1], timePoints[i]));
        return std::min(ans, 1440 - diff(timePoints[0], timePoints[n - 1]));
    }
};
