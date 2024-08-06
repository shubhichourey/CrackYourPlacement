/*
You are given an array arr[] of N integers. The task is to find the smallest positive number missing from the array.

Note: Positive number starts from 1.*/

class Solution {
public:
    int firstMissingPositive(vector<int> arr,n)
    {
        for(int i = 0; i < n; ++ i) {
            while(arr[i] >= 1 && arr[i] <= n && arr[i] != arr[arr[i]-1])
                swap(arr[i], arr[arr[i] - 1]);
        }
        
        for(int i = 0; i < n; ++ i)
            if(arr[i] != i + 1)
                return i + 1;
        
        return n + 1;
    }
};