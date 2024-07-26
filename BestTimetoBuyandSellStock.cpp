/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        if(n==0)
            return 0;
        
        vector<int> profit(n);
        vector<int> buy(n);
        int maxP=0;
        
        profit[0] = 0;
        buy[0] = prices[0];
        for(int i=1;i<n;i++)
        {
            profit[i] = max(0, prices[i]-buy[i-1]);
            maxP = max(maxP,profit[i]);
            if(profit[i]==0)
            {
                buy[i] = prices[i];
            }
            else
                buy[i] = buy[i-1];
        }
        return maxP;
    }
};