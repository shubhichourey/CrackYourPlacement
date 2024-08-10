/*Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
      int n = grid.size();
      int m = grid[0].size();

      queue < pair < pair < int, int > , int >> q;
      int vis[n][m];
      int cntFresh = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        
          if (grid[i][j] == 2) {
            q.push({{i, j}, 0}); 
           
            vis[i][j] = 2;
          }
        
          else {
            vis[i][j] = 0;
          }
     
          if (grid[i][j] == 1) cntFresh++;
        }
      }

      int tm = 0;
   
      int drow[] = {-1, 0, +1, 0};
      int dcol[] = {0, 1, 0, -1}; 
      int cnt = 0;

    
      while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();
       
        for (int i = 0; i < 4; i++) {
         
          int nrow = r + drow[i];
          int ncol = c + dcol[i];
         
          if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
         
             q.push({{nrow, ncol}, t + 1}); 
         
            vis[nrow][ncol] = 2;
            cnt++;
          }
        }
      }

     
      if (cnt != cntFresh) return -1;

      return tm;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends