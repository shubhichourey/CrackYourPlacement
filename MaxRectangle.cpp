/*Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.*/


#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here int rows = matrix.size();
    if (rows == 0) return 0;
    int cols = matrix[0].size();
    if (cols == 0) return 0;
    vector<vector<int>> max_x(rows, vector<int>(cols, 0));
    int area = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                if (j == 0)
                    max_x[i][j] = 1;
                else
                    max_x[i][j] = max_x[i][j - 1] + 1;
                int y = 1;
                int x = cols;
                while ((i - y + 1 >= 0) && (matrix[i - y + 1][j] == 1)) {
                    x = min(x, max_x[i - y + 1][j]);
                    area = max(area, x * y);
                    y++;
                }
            }
        }
    }
    return area;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

