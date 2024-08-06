/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.
*/

class Solution {
public:
 bool isPossible(vector<int>& nums,int m,int mid){
        int sum = 0,subArrays = 1;
        for(int val : nums){
            sum += val;
            if(sum > mid){
                subArrays++;
                sum = val;
            }
            if(subArrays > m){
                return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int start = nums[0],end = nums[0],mid;
        for(int val : nums){
            start = max(start,val);
            end += val;
        }
        while(start <= end){
            mid = start + (end-start)/2;
            if(isPossible(nums,k,mid)){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }
};