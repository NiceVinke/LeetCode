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

		regex re1("[q,Q,w,W,e,E,r,R,t,T,y,Y,u,U,i,I,o,O,p,P]+");
		regex re2("[a,A,s,S,d,D,f,F,g,G,h,H,j,J,k,K,l,L]+");
		regex re3("[z,Z,x,X,c,C,v,V,b,B,n,N,m,M]+");

		vector<string> ans;

		for (auto &w : words)
		{
		    if (regex_match(w, re1) ||
		        regex_match(w, re2) ||
		        regex_match(w, re3))
			          ans.push_back(w);
		}

		return ans;
	}
};
