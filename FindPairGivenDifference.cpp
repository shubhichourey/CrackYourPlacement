/*
Given an array arr[] of size n and an integer x, return 1 if there exists a pair of elements in the array whose absolute difference is x, otherwise, return -1.*/

class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
    int i = 0, j = 1;
    
    while (i < n && j < n) {
        int diff = abs(arr[j] - arr[i]);
        
        if (diff == x && i != j) {
            return 1;
        } else if (diff < x) {
            j++;
        } else {
            i++;
        }
        
        // Ensure i and j don't overlap incorrectly
        if (i == j) {
            j++;
        }
    }
    
    return -1;
    
    }
};