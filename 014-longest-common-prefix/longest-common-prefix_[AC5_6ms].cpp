// Write a function to find the longest common prefix string amongst an array of strings.


class Solution {
    string helper(string& a, string &b)
    {
        if (b.size() > a.size())
            return helper(b, a);
        for (int i = 0; i < a.size(); ++i) {
        	if (a[i] != b[i])
                return a.substr(0, i);
        }
        return a;
    }
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.empty())
            return{};
        if (strs.size() == 1)
            return strs[0];
        string ans = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            ans = helper(ans, strs[i]);
        }
        return ans;
    }
};
