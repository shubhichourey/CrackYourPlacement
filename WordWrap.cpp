/*
Given an array nums[] of size n, where nums[i] denotes the number of characters in one word. Let K be the limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly.
Assume that the length of each word is smaller than the line width. When line breaks are inserted there is a possibility that extra spaces are present in each line. The extra spaces include spaces put at the end of every line except the last one. 

You have to minimize the following total cost where total cost = Sum of cost of all lines, where cost of line is = (Number of extra spaces in the line)2.*/

vector<vector<int>>dp;
int helper(int curr,int spaces,vector<int>&nums,int &k){
    //base case
    if(curr==nums.size()){
        return 0;
    }
    
    if(dp[curr][spaces]!=-1){
        return dp[curr][spaces];
    }
    
    //continue on same line
    int a = INT_MAX;
    int newSpaces = spaces+1+nums[curr];
    if(newSpaces<=k){
        a = helper(curr+1,newSpaces,nums,k);
    }

    //start from new line
    int b = helper(curr+1,nums[curr],nums,k) + (k-spaces)*(k-spaces);

    return dp[curr][spaces] = min(a,b);
}

int solveWordWrap(vector<int>nums, int k) 
{ 
    // Code here
    int n = nums.size();
    dp.resize(n+1,vector<int>(k+1,-1));
    return helper(1,nums[0],nums,k);
} 
 
void solve(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cin>>k;
    
    cout<<solveWordWrap(nums,k)<<endl;
    
}
