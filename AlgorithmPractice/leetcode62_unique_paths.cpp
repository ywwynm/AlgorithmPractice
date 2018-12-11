#include <iostream>

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

  int uniquePaths(int m, int n) {
    int count = 0;
    dfs(1, 1, m, n, count);
    return count;
  }
};

int main() {
  Solution s;
  cout << s.uniquePaths(7, 3) << endl;
  return 0;
}