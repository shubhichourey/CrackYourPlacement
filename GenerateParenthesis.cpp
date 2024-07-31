/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/
class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
         int a=1, b=0;
        string str="(";
    
        parenthesis(a, b, str,n);
        return ans;
    }
    
    
    void parenthesis(int a , int b, string str, int n){
        if(str.length()==2*n){
            ans.push_back(str);
            return ;
        }
        
        if(a < n)
            parenthesis(a+1, b, str+'(', n);
        if(b < a)
            parenthesis(a, b+1, str+')', n);
    }
};