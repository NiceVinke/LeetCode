// Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
//
// Example 1:
//
// Input: [5, 4, 3, 2, 1]
// Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
// Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". For the left two athletes, you just need to output their relative ranks according to their scores.
//
//
//
// Note:
//
// N is a positive integer and won't exceed 10,000.
// All the scores of athletes are guaranteed to be unique.


class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums)
    {
        map<int, int, greater<int>> mp;
        vector<string> ans(nums.size(), "");
        int sub = 0;
        for (const auto &n : nums) {
            mp[n] = sub++;
        }
        string str[3]{ "Gold Medal", "Silver Medal", "Bronze Medal" };
        int cnt = 0;
        for (auto it = mp.begin(); it != mp.end(); ++it, ++cnt) {
            if (cnt < 3)
                ans[(*it).second] = str[cnt];
            else
                ans[(*it).second] = to_string(cnt + 1);
        }
        return ans;
    }
};
