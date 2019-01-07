#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int M = matrix.size(), N = matrix[0].size();
    bool shouldSetZeroForCol0 = false;
    for (int i = 0; i < M; i++) {
      if (matrix[i][0] == 0) {
        shouldSetZeroForCol0 = true;
      }

      for (int j = 1; j < N; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }
    for (int i = 1; i < M; i++) {
      for (int j = 1; j < N; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }
    if (matrix[0][0] == 0) { // should set zero for row 0
      for (int j = 0; j < N; j++) {
        matrix[0][j] = 0;
      }
    }
    if (shouldSetZeroForCol0) {
      for (int i = 0; i < M; i++) {
        matrix[i][0] = 0;
      }
    }
  }
};

void printMatrix(vector<vector<int>> matrix) {
  int M = matrix.size(), N = matrix[0].size();
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

//int main() {
//  Solution s;
//  int row0[] = { 1,0,2,3 };
//  int row1[] = { 3,4,5,2 };
//  int row2[] = { 1,3,1,5 };
//  vector<int> vrow0(row0, row0 + 4);
//  vector<int> vrow1(row1, row1 + 4);
//  vector<int> vrow2(row2, row2 + 4);
//  vector<vector<int>> matrix;
//  matrix.push_back(vrow0);
//  matrix.push_back(vrow1);
//  matrix.push_back(vrow2);
//  s.setZeroes(matrix);
//  printMatrix(matrix);
//
//  /*int row0[] = { 1,2,3,4,0 };
//  int row1[] = { 5,6,7,8,0 };
//  int row2[] = { 9,10,11,12,13 };
//  vector<int> vrow0(row0, row0 + 5);
//  vector<int> vrow1(row1, row1 + 5);
//  vector<int> vrow2(row2, row2 + 5);
//  vector<vector<int>> matrix;
//  matrix.push_back(vrow0);
//  matrix.push_back(vrow1);
//  matrix.push_back(vrow2);
//  s.setZeroes(matrix);
//  printMatrix(matrix);*/
//  return 0;
//}