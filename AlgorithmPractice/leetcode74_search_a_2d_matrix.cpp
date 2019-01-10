#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool searchRow(vector<int> row, int target) {
    int size = row.size();
    int start = 0, end = size - 1;
    int mid = (start + end) / 2;
    while (start <= end) {
      if (row[mid] == target) {
        return true;
      } else if (row[mid] > target) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
      mid = (start + end) / 2;
      cout << "searchRow: " << start << ", " << end << ", " << mid << endl;
    }
    return false;
  }

  bool searchCol(vector<vector<int>> matrix, int target) {
    const int row = matrix.size();
    int start = 0, end = row - 1;
    int mid = (start + end) / 2;
    while (start <= end) {
      if (matrix[mid][0] == target) {
        return true;
      } else if (matrix[mid][0] > target) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
      mid = (start + end) / 2;
      cout << "searchCol: " << start << ", " << end << ", " << mid << endl;
    }
    return false;
  }

  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    const int row = matrix.size();
    if (row == 0) return false;
    if (row == 1) return searchRow(matrix[0], target);
    const int col = matrix[0].size();
    if (col == 0) return false;
    if (col == 1) return searchCol(matrix, target);
    int start = 0, end = row - 1;
    int mid = (start + end) / 2;
    while (start <= end) {
      cout << "searchMatrix: " << start << ", " << end << ", " << mid << endl;
      int elemFirst = matrix[mid][0];
      if (elemFirst == target) {
        return true;
      } else if (elemFirst < target) {
        int elemLast = matrix[mid][col - 1];
        if (elemLast == target) {
          return true;
        } else if (elemLast > target) {
          return searchRow(matrix[mid], target);
        } else {
          start = mid + 1;
        }
      } else {
        end = mid - 1;
      }
      mid = (start + end) / 2;
    }
    return false;
  }

  bool best(vector<vector<int>>& matrix, int target) {
    const int m = matrix.size();
    if (m == 0) return false;
    const int n = matrix[0].size();
    if (n == 0) return false;
    int start = 0, end = m * n - 1;
    int mid = (start + end) / 2;
    while (start <= end) {
      int r = mid / n, c = mid % n;
      cout << "best search: " << start << ", " << end << ", " << mid << ", " << r << ", " << c << endl;
      int value = matrix[r][c];
      if (value == target) {
        return true;
      } else if (value < target) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
      mid = (start + end) / 2;
    }
    return false;
  }
};

//int main() {
//  /*int row[] = { 1,3,5,6,8,12,17,20,21 };
//  vector<int> v_row(row, row + 9);
//  Solution s;
//  cout << s.searchRow(v_row, 1);*/
//  /*int row1[] = { 1,3,5,7 };
//  int row2[] = { 10,11,16,20 };
//  int row3[] = { 23,30,34,50 };
//  vector<int> v_row1(row1, row1 + 4);
//  vector<int> v_row2(row2, row2 + 4);
//  vector<int> v_row3(row3, row3 + 4);
//  vector<vector<int>> matrix;
//  matrix.push_back(v_row1);
//  matrix.push_back(v_row2);
//  matrix.push_back(v_row3);
//  Solution s;
//  cout << s.searchMatrix(matrix, 26) << endl;*/
//
//  /*int row1[] = { 1 };
//  vector<int> v_row1(row1, row1 + 1);
//  vector<vector<int>> matrix;
//  matrix.push_back(v_row1);
//  Solution s;
//  cout << s.best(matrix, 1) << endl;*/
//
//  /*int row1[] = { 1 };
//  int row2[] = { 10 };
//  int row3[] = { 23 };
//  int row4[] = { 31 };
//  int row5[] = { 32 };
//  vector<int> v_row1(row1, row1 + 1);
//  vector<int> v_row2(row2, row2 + 1);
//  vector<int> v_row3(row3, row3 + 1);
//  vector<int> v_row4(row4, row4 + 1);
//  vector<int> v_row5(row5, row5 + 1);
//  vector<vector<int>> matrix;
//  matrix.push_back(v_row1);
//  matrix.push_back(v_row2);
//  matrix.push_back(v_row3);
//  matrix.push_back(v_row4);
//  matrix.push_back(v_row5);
//  Solution s;
//  cout << s.best(matrix, 1) << endl;*/
//
//  /*int row1[] = { 1,1 };
//  int row2[] = { 2,2 };
//  vector<int> v_row1(row1, row1 + 2);
//  vector<int> v_row2(row2, row2 + 2);
//  vector<vector<int>> matrix;
//  matrix.push_back(v_row1);
//  matrix.push_back(v_row2);
//  Solution s;
//  cout << s.best(matrix, 1) << endl;*/
//
//  return 0;
//}