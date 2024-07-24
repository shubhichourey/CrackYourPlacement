/*Given a string s, return true if the s can be palindrome after deleting at most one character from it.*/

class Solution {
public:
    bool validPalindrome(string s) {
        for (int l = 0, r = s.length() - 1; l < r; ++l, --r)
      if (s[l] != s[r])
        return validPalindrome(s, l + 1, r) ||  //
               validPalindrome(s, l, r - 1);
    return true;
  }

 private:
  bool validPalindrome(const string& s, int l, int r) {
    while (l < r)
      if (s[l++] != s[r--])
        return false;
    return true;
    }
};