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
        vector<string> rtn;
        
        for (auto w : words) {
            int r1 = 0, r2 = 0, r3 = 0;
            for (auto c : w) {
                switch (c) {
                    case 'q': case 'w': case 'e': case 'r': case 't': case 'y': case 'u': case 'i': case 'o': case 'p':
                    case 'Q': case 'W': case 'E': case 'R': case 'T': case 'Y': case 'U': case 'I': case 'O': case 'P':
                    r1 = 1;
                    break;
                    
                    case 'a': case 's': case 'd': case 'f': case 'g': case 'h': case 'j': case 'k': case 'l':
                    case 'A': case 'S': case 'D': case 'F': case 'G': case 'H': case 'J': case 'K': case 'L':
                    r2 = 1;
                    break;
                    
                    case 'z': case 'x': case 'c': case 'v': case 'b': case 'n': case 'm':
                    case 'Z': case 'X': case 'C': case 'V': case 'B': case 'N': case 'M':
                    r3 = 1;
                    break;
                }
                
                if (1 < r1 + r2 + r3) break;
            }
            
            if (1 == r1 + r2 + r3) rtn.push_back(w);
        }
        
        return rtn;
    }
};
