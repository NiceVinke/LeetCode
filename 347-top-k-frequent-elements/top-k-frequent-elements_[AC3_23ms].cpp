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
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (const auto &n : nums)
            ++m[n];
        for (const auto &pr : m) {
            pq.push(make_pair(pr.second, pr.first));
            if (pq.size() > k)
                pq.pop();
        }
        while (!pq.empty()) {
            ans.emplace_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
