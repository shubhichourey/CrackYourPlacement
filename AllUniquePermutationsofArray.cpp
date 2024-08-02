/*
Given an array arr[] of length n. Find all possible unique permutations of the array in sorted order. A sequence A is greater than sequence B if there is an index i for which Aj = Bj for all j<i and Ai > Bi.*/

class Solution {
  public:
   void solve(vector<int>&arr, int n, int ind, set<vector<int>>&s){
        if(ind>=n){
            return ;
        }
        for(int i=ind;i<n;i++){
            swap(arr[i], arr[ind]);
            s.insert(arr);
            solve(arr, n, ind+1, s);
            
            swap(arr[i], arr[ind]);
        }
        return;
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
         vector<vector<int>>ans;
        set<vector<int>>s;
        
        solve(arr, n, 0, s);
        
        for(auto it:s){
            ans.push_back(it);
        }
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};