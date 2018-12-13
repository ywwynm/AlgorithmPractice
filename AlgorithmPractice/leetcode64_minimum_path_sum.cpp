#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    const int INF = 0x3F3F3F3F;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INF));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
      if (i == 0 && j == 0) continue;
      int a = INF, b = INF;
      if (i > 0) {
        a = dp[i - 1][j] + grid[i][j];
      }
      if (j > 0) {
        b = dp[i][j - 1] + grid[i][j];
      }
      if (a < b) {
        dp[i][j] = a;
      } else {
        dp[i][j] = b;
      }
    }
    return dp[m - 1][n - 1];
  }
};

int main() {
  Solution s;
  int row1[3] = { 1,3,1 };
  int row2[3] = { 1,5,1 };
  int row3[3] = { 4,2,1 };
  vector<int> v_row1(row1, row1 + 3);
  vector<int> v_row2(row2, row2 + 3);
  vector<int> v_row3(row3, row3 + 3);
  vector<vector<int>> grid;
  grid.push_back(v_row1);
  grid.push_back(v_row2);
  grid.push_back(v_row3);
  cout << s.minPathSum(grid) << endl;
  return 0;
}