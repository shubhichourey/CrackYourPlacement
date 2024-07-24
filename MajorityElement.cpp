/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(int i=0;i<32;i++)
        {
            int ones=0;
            for(auto x: nums)
            {
                if((1<<i)& x){
                    ones+=1;
                }
            }
            if(ones>(n/2)) ans |=(1<<i);
        }
        return ans;
        
    }
};