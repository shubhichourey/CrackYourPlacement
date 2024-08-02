/*According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
         const int n = board.size();
    const int m = board[0].size();

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        int ones = 0;
        for (int x = max(0, i - 1); x < min(n, i + 2); ++x)
          for (int y = max(0, j - 1); y < min(m, j + 2); ++y)
            ones += board[x][y] & 1;
        
        if (board[i][j] == 1 && (ones == 3 || ones == 4))
          board[i][j] |= 0b10;
        
        if (board[i][j] == 0 && ones == 3)
          board[i][j] |= 0b10;
      }

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        board[i][j] >>= 1;
    }
};