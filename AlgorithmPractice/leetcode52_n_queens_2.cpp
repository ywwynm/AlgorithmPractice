#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int N;
  int totalCount;

  int totalNQueens(int n) {
    N = n;
    totalCount = 0;
    vector<int> solution;
    solveNQueens(solution, 0);
    return totalCount;
  }

  void solveNQueens(vector<int>& solution, int row) {
    if (row == N) {
      totalCount++;
    } else {
      for (int i = 0; i < N; i++) {
        if (!cannotPlaceChess(solution, row, i)) {
          solution.push_back(i);
          solveNQueens(solution, row + 1);
          solution.pop_back();
        }
      }
    }
  }

  bool cannotPlaceChess(vector<int> arr, int row, int x) {
    for (int i = 0; i < arr.size(); i++) {
      int c = arr[i];
      if (c == x) return true;
      int gap = row - i;
      if (gap == x - c || gap == c - x) return true;
    }
    return false;
  }
};

int main() {
  Solution s;
  int count = s.totalNQueens(4);
  cout << count << endl;
  return 0;
}