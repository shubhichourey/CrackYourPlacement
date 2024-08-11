/*You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans;
    vector<pair<char, int>> stack;

    for (const char c : s)
      if (stack.empty() || stack.back().first != c)
        stack.emplace_back(c, 1);
      else if (++stack.back().second == k)  // stack[-1] == c
        stack.pop_back();

    for (const auto& [c, count] : stack)
      ans.append(count, c);

    return ans;
    }
};