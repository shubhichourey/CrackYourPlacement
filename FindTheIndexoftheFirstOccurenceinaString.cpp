/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=0;
        if(needle.size()<=haystack.size())
        {
        for(int i=0;i<=haystack.size()-needle.size();i++)
        {
            if(haystack.substr(i,needle.size())==needle)
            {
                n=i;
                break;
            }
            else
            {
                n=-1;
            }
        }
        }
        else
        {
            n=-1;
        }
        return n;
    }
};