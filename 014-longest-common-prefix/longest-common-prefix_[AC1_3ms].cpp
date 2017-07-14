// Write a function to find the longest common prefix string amongst an array of strings.


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int n = strs.size();
        if (n == 0) return{};
        if (n == 1) return strs[0];
        for (int pos = 0; pos < strs[0].size(); ++pos)
            for (int i = 1; i < n; ++i)
                if (strs[i][pos] != strs[0][pos])
                    return strs[0].substr(0, pos);
        return strs[0];
    }
};
