/*Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.*/


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
      int n = nums.size();
        
        vector<int> result; 
        for(int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            
            if(nums[num-1] < 0) {
                result.push_back(num);
            } else {
                nums[num-1] *= -1;
            }
        }
        
        return result;  
    }
};