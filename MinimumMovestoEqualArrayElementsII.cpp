/*Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer.
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
         const int n = nums.size();
    nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
    const int median = nums[n / 2];
    return accumulate(nums.begin(), nums.end(), 0, [&](int subtotal, int num) {
      return subtotal + abs(num - median);
    });
    }
};