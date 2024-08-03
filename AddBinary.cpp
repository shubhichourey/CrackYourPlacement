/*Given two binary strings a and b, return their sum as a binary string.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int num1 = a.length();   
        int num2 = b.length();
        
        int i= num1-1;
        int j = num2-1;
        int carry = 0;
        string  ans = "";
        while(i>=0 || j>=0 || carry)
        {
            int x,y;
            if(i>=0)
            {
                x = a[i]-'0';
                i--;
            }
            else{
                x = 0;
            }
            
            if(j>=0)
            {
                y = b[j]-'0';
                j--;
            }
            else{
                y = 0;
            }
            
            int sum = x+y+carry;
            ans += (sum%2)+'0';
            carry = (sum/2);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};