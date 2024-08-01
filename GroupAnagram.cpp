/*Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector <string>>umap;

        for(auto x: strs)
        {
            string temp=x;
            sort(x.begin(),x.end());
            umap[x].push_back(temp);
        }
        for (auto x:umap)
        {
            ans.push_back(x.second);
        }
        return ans;
        
    }
};