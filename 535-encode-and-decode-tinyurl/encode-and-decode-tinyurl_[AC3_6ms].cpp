// Note: This is a companion problem to the System Design problem: Design TinyURL.
//
// TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.
//
// Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.


class Solution {
    unordered_map<string, string> table;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        auto hash = std::hash<string>()(longUrl);
        string str = to_string(hash);
        str.resize(8);
        table.emplace(str, longUrl);
        return "http://tinyurl.com/" + str;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return table[shortUrl.substr(19, 8)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
