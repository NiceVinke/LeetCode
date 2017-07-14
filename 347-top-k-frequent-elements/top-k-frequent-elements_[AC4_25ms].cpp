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
        vector<int> ans;
        unordered_map<int, int> m;
        for (const auto &n : nums)
            ++m[n];
        vector<pair<int, int>> heap;
        for (const auto &pr : m)
            heap.emplace_back(make_pair(pr.second, pr.first));
        make_heap(heap.begin(), heap.end());
        while (k--) {
            ans.emplace_back(heap.front().second);
            pop_heap(heap.begin(), heap.end());
            heap.pop_back();
        }
        return ans;
    }
};
