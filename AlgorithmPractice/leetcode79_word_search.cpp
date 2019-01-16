#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

  bool dfs(vector<vector<char>>& board, string word, int i, int j, int wi, vector<vector<bool>>& in) {
    if (board[i][j] == word[wi] && !in[i][j]) {
      in[i][j] = true;
      if (wi == word.size() - 1) return true;

      bool top = false;
      if (i - 1 >= 0) top = dfs(board, word, i - 1, j, wi + 1, in);
      if (top) return true;

      bool bottom = false;
      if (i + 1 <= board.size() - 1) bottom = dfs(board, word, i + 1, j, wi + 1, in);
      if (bottom) return true;

      bool left = false;
      if (j - 1 >= 0) left = dfs(board, word, i, j - 1, wi + 1, in);
      if (left) return true;

      bool right = false;
      if (j + 1 <= board[0].size() - 1) right = dfs(board, word, i, j + 1, wi + 1, in);
      if (right) return true;

      in[i][j] = false;
    }
    return false;
  }

  bool exist(vector<vector<char>>& board, string word) {
    int M = board.size(), N = board[0].size();
    vector<vector<bool>> in(M, vector<bool>(N, false));
    for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) {
      if (dfs(board, word, i, j, 0, in)) {
        return true;
      }
    }
    return false;
  }

};

//int main() {
//  char row1[] = { 'A','B','C','E' };
//  char row2[] = { 'S','F','C','S' };
//  char row3[] = { 'A','D','E','E' };
//  /*char row1[] = { 'a','a','a','a' };
//  char row2[] = { 'a','a','a','a' };
//  char row3[] = { 'a','a','a','a' };*/
//  vector<char> vrow1(row1, row1 + 4);
//  vector<char> vrow2(row2, row2 + 4);
//  vector<char> vrow3(row3, row3 + 4);
//  vector<vector<char>> board;
//  board.push_back(vrow1);
//  board.push_back(vrow2);
//  board.push_back(vrow3);
//  Solution s;
//  cout << s.exist(board, "SEE") << endl;
//  return 0;
//}