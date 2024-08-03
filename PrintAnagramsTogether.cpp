/*Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.

Note: The final output will be in lexicographic order.
*/

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> ans;
        unordered_map<string, vector<string>>umap;
        
        for(auto x: string_list){
            string temp = x;
            sort(x.begin(), x.end());
            umap[x].push_back(temp);
        }
      
        for(auto x : umap){
            ans.push_back(x.second);
        }
        return ans;
    }
};