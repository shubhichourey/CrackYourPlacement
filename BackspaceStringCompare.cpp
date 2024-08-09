/*Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
         return backspace(s) == backspace(t);
    }
    private:
  string backspace(const string& s) {
    string stack;
    for (const char c : s)
      if (c != '#')
        stack.push_back(c);
      else if (!stack.empty())
        stack.pop_back();
    return stack;
  }
};