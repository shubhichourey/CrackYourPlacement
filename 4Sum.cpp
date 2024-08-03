/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
 vector<vector<int>> ans;
    vector<int> arr;
    ranges::sort(nums);
    nSum(nums, 4, target, 0, nums.size() - 1, arr, ans);
    return ans;
  }

 private:
  // Finds n numbers that add up to the target in [l, r].
  void nSum(const vector<int>& nums, long n, long target, int l, int r,
            vector<int>& arr, vector<vector<int>>& ans) {
    if (r - l + 1 < n || target < nums[l] * n || target > nums[r] * n)
      return;
    if (n == 2) {
      // Similar to the sub procedure in 15. 3Sum
      while (l < r) {
        const int sum = nums[l] + nums[r];
        if (sum == target) {
          arr.push_back(nums[l]);
          arr.push_back(nums[r]);
          ans.push_back(arr);
          arr.pop_back();
          arr.pop_back();
          ++l;
          --r;
          while (l < r && nums[l] == nums[l - 1])
            ++l;
          while (l < r && nums[r] == nums[r + 1])
            --r;
        } else if (sum < target) {
          ++l;
        } else {
          --r;
        }
      }
      return;
    }

    for (int i = l; i <= r; ++i) {
      if (i > l && nums[i] == nums[i - 1])
        continue;
     arr.push_back(nums[i]);
      nSum(nums, n - 1, target - nums[i], i + 1, r, arr, ans);
      arr.pop_back();
    }
    }
};