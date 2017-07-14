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
        if (n > 1440) return 0;
        array<int, 1440> times{ 0 };
        auto minutes = [](string &t) {return ((t[0] - '0') * 10 + t[1] - '0') * 60 + (t[3] - '0') * 10 + t[4] - '0'; };
        for (auto &t : timePoints)
            if (times[minutes(t)]++) return 0;
        int ans = INT_MAX, prev = 0, first = 0, last = 0;
        while (!times[first]) ++first;
        prev = first;
        for (int i = first + 1; i < 1440; ++i) {
            if (times[i]) {
                ans = std::min(ans, i - prev);
                last = prev = i;
            }
        }
        return std::min(ans, 1440 - (last - first));
    }
};
