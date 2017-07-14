// Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below. 
//
//
//
//
//
//
//
// Example 1:
//
// Input: ["Hello", "Alaska", "Dad", "Peace"]
// Output: ["Alaska", "Dad"]
//
//
//
// Note:
//
// You may use one character in the keyboard more than once.
// You may assume the input string will only contain letters of alphabet.


class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string line1 = "qwertyuiopQWERTYUIOP";
        string line2 = "asdfghjklASDFGHJKL";
        string line3 = "zxcvbnmZXCVBNM";
        vector<string> results;
        
        for (int i=0; i<words.size(); ++i){
            bool inL1 = words[i].find_first_not_of(line1) == string::npos;
            bool inL2 = words[i].find_first_not_of(line2) == string::npos;
            bool inL3 = words[i].find_first_not_of(line3) == string::npos;
            
            if (inL1 || inL2 || inL3){
                results.push_back(words[i]);
            }
        }
        
        return results;
    }
};
