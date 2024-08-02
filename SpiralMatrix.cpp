/*Given an m x n matrix, return all elements of the matrix in spiral order.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int> v;
        int rstart=0,rend=matrix.size(),cstart=0,cend=matrix[0].size();
        while(rstart<rend&&cstart<cend)
        {
            for(int i=cstart;i<cend;i++)
            {
                v.push_back(matrix[rstart][i]);
            }
            rstart++;
            for(int i=rstart;i<rend;i++)
            {
                v.push_back(matrix[i][cend-1]);
            }
            cend--;
            if(rstart<rend){
            for(int i=cend-1;i>=cstart;i--)
            {
                v.push_back(matrix[rend-1][i]);
            }
            rend--;}
            if(cstart<cend){
            for(int i=rend-1;i>=rstart;i--)
            {
                v.push_back(matrix[i][cstart]);
            }
            cstart++;}
        }
        
        cout<<matrix[0].size();
        return v;
    }
};