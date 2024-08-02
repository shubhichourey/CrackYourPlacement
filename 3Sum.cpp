/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         int len=nums.size();
        if(len==0 || len<3) 
            return {};
        set<vector<int>> s; 
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<len-2;i++){
            for(int j=i+1;j<len-1;j++){
                for(int k=j+1;k<len;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        s.insert({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }
       
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};