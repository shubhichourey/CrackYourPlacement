/*Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n);
        stack<int> s;
        for(int i=n-1;i>=0;i--) {
            while(!s.empty() && temperatures[i]>=temperatures[s.top()]) s.pop();
            if(s.empty()) {
                ans[i]=0;
            }
            else {
                ans[i]=s.top()-i;
            }
            s.push(i);
        }
        return ans;
    }
};