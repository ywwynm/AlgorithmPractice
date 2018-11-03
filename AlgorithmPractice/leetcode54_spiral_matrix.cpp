#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int m = matrix.size();
    if (m == 0) return res;
    int n = matrix[0].size();
    if (n == 0) return res;
    int SQR;
    if (m < n) {
      SQR = m / 2 + m % 2;
    } else {
      SQR = n / 2 + n % 2;
    }
    int rowCount = 0, colCount = 0; // 已经遍历过的行列数目
    int sqr = 0; // 当前所处第几个4步循环
    vector<vector<bool>> visited;
    for (int i = 0; i < m; i++) {
      vector<bool> tmp;
      for (int j = 0; j < n; j++) {
        tmp.push_back(false);
      }
      visited.push_back(tmp);
    }
    while (sqr < SQR) {
      for (int i = 0; i < n - 2 * sqr; i++) {
        int a = sqr, b = sqr + i;
        res.push_back(matrix[a][b]);
        //cout << "1: " <<  a << ", " << b << endl;
        visited[a][b] = true;
      }
      for (int i = 0; i < m - 2 * sqr - 1; i++) {
        int a = sqr + 1 + i, b = n - sqr - 1;
        if (visited[a][b] || a >= m) {
          //cout << "2: " << a << ", " << b << " has problem" << endl;
          return res;
        }
        res.push_back(matrix[a][b]);
        //cout << "2: " << a << ", " << b << endl;
        visited[a][b] = true;
      }
      for (int i = 0; i < n - 2 * sqr - 1; i++) {
        int a = m - sqr - 1, b = n - sqr - 2 - i;
        if (visited[a][b] || b < 0) {
          //cout << "3: " << a << ", " << b << " has problem" << endl;
          return res;
        }
        res.push_back(matrix[a][b]);
        //cout << "3: " << a << ", " << b << endl;
        visited[a][b] = true;
      }
      for (int i = 0; i < m - 2 * sqr - 2; i++) {
        int a = m - sqr - 2 - i, b = sqr;
        if (visited[a][b] || a < 0) {
          //cout << "4: " << a << ", " << b << " has problem" << endl;
          return res;
        }
        res.push_back(matrix[a][b]);
        //cout << "4: " << a << ", " << b << endl;
        visited[a][b] = true;
      }
      sqr++;
    }
    return res;
  }
};

int main() {
  vector<vector<int>> matrix;
  /*int row1Arr[] = { 1,2,3,4 };
  vector<int> row1(row1Arr, row1Arr + 4);
  int row2Arr[] = { 5,6,7,8 };
  vector<int> row2(row2Arr, row2Arr + 4);
  int row3Arr[] = { 9,10,11,12 };
  vector<int> row3(row3Arr, row3Arr + 4);
  matrix.push_back(row1);
  matrix.push_back(row2);
  matrix.push_back(row3);*/
  Solution s;
  vector<int> res = s.spiralOrder(matrix);
  for (auto i : res) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}