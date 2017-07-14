// Given a non-empty array of integers, return the k most frequent elements.
//
// For example,
// Given [1,1,1,2,2,3] and k = 2, return [1,2].
//
//
// Note: 
//
// You may assume k is always valid, 1 ? k ? number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans(k);
        unordered_map<int, int> m;
        vector<vector<int>> buckets(nums.size() + 1);
        for (const auto &n : nums)
            ++m[n];
        for (const auto &pr : m)
            buckets[pr.second].emplace_back(pr.first);
        for (int i = buckets.size() - 1, cnt = 0; i >= 0; --i) {
            for (const auto &n : buckets[i])
                ans[cnt++] = n;
            if (cnt == k)
                break;
        }
        return ans;
    }
};
