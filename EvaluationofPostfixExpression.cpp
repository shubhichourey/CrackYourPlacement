/*Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.
*/

//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        for(int i=0;i<S.size();i++){
            if(isdigit(S[i]))
            st.push(S[i]-'0');
            else{
                int value1=st.top(); 
                st.pop();
                int value2=st.top();
                st.pop();
                switch(S[i])
                {
                    case '+':st.push(value2 + value1);  
                    break;
                    case '-': st.push(value2 - value1); 
                    break;
                    case '*': st.push(value2 * value1);
                    break;
                    case '/': st.push(value2 / value1);
                }
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends