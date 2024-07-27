/*
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.
*/
class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(),m=t.size();
        unordered_map<int,int> mp;
        for(auto x:t) mp[x]++;
        int l=0,r=0,i=0,j=1e9;
        while(r<n){
            if(mp[s[r++]]-->0) m-=1;
            while(m==0){
                if(r-l<j){
                    j=r-l;
                    i=l;
                }
                if(mp[s[l++]]++==0)m+=1;
            }
        }
        return j==1e9 ? "":s.substr(i,j);
    }
};