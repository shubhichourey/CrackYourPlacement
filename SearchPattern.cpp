/*
Given two strings, one is a text string and the other is a pattern string. The task is to print the starting indexes of all the occurrences of the pattern string in the text string. For printing, the Starting Index of a string should be taken as 1. The strings will only contain lowercase English alphabets ('a' to 'z').*/

class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            vector<int>res;
            int q=101;
            int d=26;
            int M=pattern.size();
            int N=text.size();
            int p=0;
            int t=0;
            int h=1;
            
            for(int i=0;i<M-1;i++){
                h=(h*d)%q;
            }
            
          
            for(int i=0;i<M;i++){
                p=(d*p+pattern[i])%q;
                t=(d*t+text[i])%q;
            }
            
          
            for(int i=0;i<=N-M;i++){
              
                if(p==t){
                    
                    int j=0;
                    for(j=0;j<M;j++){
                        if(text[i+j]!=pattern[j]){
                            break;
                        }
                    }
                    if(j==M){
                        res.push_back(i+1);
                    }
                    
                }
                if(i<N-M){
                    t=(d*(t-text[i]*h)+text[i+M])%q;
                    if(t<0){
                        t=t+q;
                    }
                }
            }
            return res;
        }
};