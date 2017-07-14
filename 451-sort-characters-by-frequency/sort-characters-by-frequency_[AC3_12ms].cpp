// Given a string, sort it in decreasing order based on the frequency of characters.
//
// Example 1:
//
// Input:
// "tree"
//
// Output:
// "eert"
//
// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
//
//
//
// Example 2:
//
// Input:
// "cccaaa"
//
// Output:
// "cccaaa"
//
// Explanation:
// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.
//
//
//
// Example 3:
//
// Input:
// "Aabb"
//
// Output:
// "bbAa"
//
// Explanation:
// "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.


class Solution {
public:
    string frequencySort(string s)
    {
        string ans;
        pair<char, int> freq[256] = { {0, 0} };
        for (const auto &c : s) {
            freq[c].first = c;
            ++freq[c].second;
        }
        sort(begin(freq), end(freq),
            [](pair<char, int>& l, pair<char, int>& r) {
            return l.second > r.second;
        });
        for (auto it = begin(freq); it != end(freq); ++it)
            ans.append(it->second, it->first);
        return ans;
    }
};
