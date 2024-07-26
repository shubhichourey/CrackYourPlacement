/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/

class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<char> str;
        for(int i=0;i<n;i++) {
            if(str.empty()) {
                if(s[i]=='(' || s[i]=='{' || s[i]=='[') str.push(s[i]);
                else return false;
            }
            else if(s[i]=='(' || s[i]=='{' || s[i]=='[') str.push(s[i]);
            else {
                if(str.top()=='(' && s[i]==')') str.pop();
                else if(str.top()=='[' && s[i]==']') str.pop();
                else if(str.top()=='{' && s[i]=='}') str.pop();
                else return false;
            }
        }
        if(str.size()==0) return true;
        return false;
    }
};