/*You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                int x=stack.top();
                stack.pop();
                int y=stack.top();
                stack.pop();
                stack.push(x+y);
            }
            else if(tokens[i]=="-"){
                int x=stack.top();
                stack.pop();
                int y=stack.top();
                stack.pop();
                stack.push(y-x);
            }
            else if(tokens[i]=="*"){
                int x=stack.top();
                stack.pop();
                int y=stack.top();
                stack.pop();
                stack.push(x*y);
            }
            else if(tokens[i]=="/"){
                int x=stack.top();
                stack.pop();
                int y=stack.top();
                stack.pop();
                x=y/x;
                stack.push(x);
            }
            else{
                
                stack.push(stoi(tokens[i]));
            }
        }
        return stack.top();
    }
};