#include <iostream>
#include <vector>
#include <queue>

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

  int fasterDP(vector<vector<int>>& grid) {
    const int INF = 0x3f3f3f3f;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
      if (i > 0 || j > 0) {
        int a = i > 0 ? dp[i - 1][j] : INF;
        int b = j > 0 ? dp[i][j - 1] : INF;
        dp[i][j] = min(a, b) + grid[i][j];
      }
    }
    return dp[m - 1][n - 1];
  }

  int spfa(vector<vector<int>>& grid) {
    const int INF = 0x3F3F3F3F;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dis(m, vector<int>(n, INF));
    vector<vector<bool>> in_q(m, vector<bool>(n, false));
    dis[0][0] = grid[0][0];
    queue<int> qx, qy;
    qx.push(0); qy.push(0);
    while (!qx.empty()) {
      int x = qx.front(), y = qy.front();
      qx.pop(); qy.pop();
      in_q[x][y] = false;
      if (x + 1 < m) {
        if (dis[x + 1][y] > dis[x][y] + grid[x + 1][y]) {
          dis[x + 1][y] = dis[x][y] + grid[x + 1][y];
        }
        if (!in_q[x + 1][y]) {
          qx.push(x + 1); qy.push(y);
          in_q[x + 1][y] = true;
        }
      }
      if (y + 1 < n) {
        if (dis[x][y + 1] > dis[x][y] + grid[x][y + 1]) {
          dis[x][y + 1] = dis[x][y] + grid[x][y + 1];
        }
        if (!in_q[x][y + 1]) {
          qx.push(x); qy.push(y + 1);
          in_q[x][y + 1] = true;
        }
      }
    }
    return dis[m - 1][n - 1];
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
  cout << s.fasterDP(grid) << endl;
  return 0;
}