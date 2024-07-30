/*Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int s1 = 0, count = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        
        for(int i=0;i<n;i++){
            s1 += nums[i];
            int remove = s1 - k;
            count += mp[remove];
            mp[s1] += 1;
        }

        return count;
    }
};