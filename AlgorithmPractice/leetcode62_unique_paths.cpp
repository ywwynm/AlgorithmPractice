#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
  void dfs(int x, int y, int m, int n, int& count) {
    if (x == m && n == y) {
      count++;
    }
    if (x + 1 <= m) {
      dfs(x + 1, y, m, n, count);
    }
    if (y + 1 <= n) {
      dfs(x, y + 1, m, n, count);
    }
  }

  int bfs(int m, int n) {
    int count = 0;
    queue<int> qx, qy;
    qx.push(1); qy.push(1);
    while (!qx.empty()) {
      int x = qx.front(), y = qy.front();
      if (x == m && y == n) {
        count++;
      }
      qx.pop(); qy.pop();
      if (x + 1 <= m) {
        qx.push(x + 1); qy.push(y);
      }
      if (y + 1 <= n) {
        qx.push(x); qy.push(y + 1);
      }
    }
    return count;
  }

  int uniquePaths(int m, int n) {
    /*int count = 0;
    dfs(1, 1, m, n, count);
    return count;*/
    return bfs(m, n);
  }
};

int main() {
  Solution s;
  cout << s.uniquePaths(28, 12) << endl;
  return 0;
}