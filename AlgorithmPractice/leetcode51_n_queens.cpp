#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int N;

  vector<vector<string>> solveNQueens(int n) {
    N = n;
    vector<vector<string>> solutions;
    vector<int> solution;
    solveNQueens(solutions, solution, 0);
    return solutions;
  }

  void solveNQueens(vector<vector<string>>& solutions, vector<int>& solution, int row) {
    if (row == N) {
      addNewSolution(solutions, solution);
    } else {
      for (int i = 0; i < N; i++) {
        if (!cannotPlaceChess(solution, row, i)) {
          solution.push_back(i);
          solveNQueens(solutions, solution, row + 1);
          solution.pop_back();
        }
      }
    }
  }

  bool cannotPlaceChess(vector<int> arr ,int row, int x) {
    for (int i = 0; i < arr.size(); i++) {
      int c = arr[i];
      if (c == x) return true;
      int gap = row - i;
      if (gap == x - c || gap == c - x) return true;
    }
    return false;
  }

  void addNewSolution(vector<vector<string>>& solutions, vector<int> numSolution) {
    vector<string> solution;
    for (auto idx : numSolution) {
      string s = "";
      for (int i = 0; i < N; i++) s += '.';
      s[idx] = 'Q';
      solution.push_back(s);
    }
    solutions.push_back(solution);
  }
};

int main() {
  Solution s;
  vector<vector<string>> solutions = s.solveNQueens(4);
  cout << solutions.size() << endl;
  return 0;
}