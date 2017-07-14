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
        vector<pair<int, int>> prs;
        for (const auto &n : nums)
            ++m[n];
        for (const auto &pr : m)
            prs.emplace_back(make_pair(-pr.second, pr.first));
        nth_element(prs.begin(), prs.begin() + k - 1, prs.end());
        for (int i = 0; i < k; ++i)
            ans[i] = prs[i].second;
        return ans;
    }
};
