// Write a function to find the longest common prefix string amongst an array of strings.


class Solution {
    int common;
    int helper(string& a, string &b)
    {
        int size = std::min(static_cast<int>(std::min(a.size(), b.size())), common);
        for (int i = 0; i < size; ++i) {
        	if (a[i] != b[i])
                return i;
        }
        return size;
    }
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.empty()) return{};
        if (strs.size() == 1) return strs[0];
        common = INT_MAX;
        for (int i = 1; i < strs.size(); ++i) {
            if (!(common = helper(strs[i - 1], strs[i])))
                return{};
        }
        return strs[0].substr(0, common);
    }
};
