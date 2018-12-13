#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (m == 1 && n == 1 && obstacleGrid[0][0] == 0) return 1;
    vector<vector<int>> dp(m, vector<int>(n, 1));
    dp[m - 1][n - 1] = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (obstacleGrid[i][j] == 1) {
          dp[i][j] = 0;
        } else if (i > 0 && j > 0) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        } else if (i > 0) {
          dp[i][j] = dp[i - 1][j];
        } else if (j > 0) {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};

//int main() {
//  Solution s;
//  vector<vector<int>> grid;
//  grid.push_back(vector<int>(2, 0));
//  /*grid.push_back(vector<int>(3, 0));
//  grid.push_back(vector<int>(3, 0));
//  grid[1][1] = 1;*/
//  cout << s.uniquePathsWithObstacles(grid) << endl;
//  return 0;
//}