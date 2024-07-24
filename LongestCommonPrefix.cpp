/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ans = strs[0].length(), n = strs.size();
        for(int i=1; i<n; i++){
            int j = 0;
            while(j<strs[i].length() && strs[i][j]==strs[0][j])j++;
            ans = min(ans, j);
        }
        return strs[0].substr(0, ans);
    
    }
};