// Write a function to find the longest common prefix string amongst an array of strings.


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.empty()) return{};
        if (strs.size() == 1) return strs[0];
        int common = INT_MAX;
        for (const auto &s : strs)
            common = std::min(static_cast<int>(s.size()), common);

        for (int i = 1; i < strs.size(); ++i) {
            for (int j = 0; j < common; ++j) {
                if (strs[i - 1][j] != strs[i][j])
                    if (!(common = j))
                        return{};
            }
        }
        return strs[0].substr(0, common);
    }
};
