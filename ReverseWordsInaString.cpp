/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.*/

class Solution {
public:
    string reverseWords(string s) {
        string ans;
		int n=s.size();
		int i=n-1,j=n-1;
		while(i>=0 && j>=0){
			while(i>=0 && s[i]!=' '){
				i--;
			}
			if(s[j]!=' ') ans+=s.substr(i+1,j-i)+' ';
			i--;
			j=i;
		}
		return ans.substr(0,ans.size()-1);
    }
};