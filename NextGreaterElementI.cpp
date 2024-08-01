/*The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
    unordered_map<int, int> numToNextGreater;
    stack<int> stack;  // a decreasing stack

    for (const int num : nums2) {
      while (!stack.empty() && stack.top() < num)
        numToNextGreater[stack.top()] = num, stack.pop();
      stack.push(num);
    }

    for (const int num : nums1)
      if (const auto it = numToNextGreater.find(num);
          it != numToNextGreater.cend())
        ans.push_back(it->second);
      else
        ans.push_back(-1);

    return ans;
    }
};