/*Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.*/

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int ans = 0;
    vector<int> stack{INT_MAX};

    for (const int a : arr) {
      while (stack.back() <= a) {
        const int mid = stack.back();
        stack.pop_back();

        ans += min(stack.back(), a) * mid;
      }
      stack.push_back(a);
    }

    for (int i = 2; i < stack.size(); ++i)
      ans += stack[i] * stack[i - 1];

    return ans;
    }
};