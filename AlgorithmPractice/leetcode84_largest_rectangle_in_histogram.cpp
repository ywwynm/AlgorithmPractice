#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int maxArea = 0;
    const int size = heights.size();
    vector<vector<int>> dp(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++) {
      for (int j = i; j < size; j++) {
        int area;
        if (i == j) {
          dp[i][j] = i;
          area = heights[i];
        } else {
          int x = dp[i][j - 1];
          dp[i][j] = heights[j] < heights[x] ? j : x;
          area = heights[dp[i][j]] * (j - i + 1);
        }
        // cout << i << ", " << j << " -> minHeightIdx: " << dp[i][j] << ", area: " << area << endl;
        if (area > maxArea) maxArea = area;
      }
    }
    return maxArea;
  }
};

int main() {
  vector<int> heights = { 2,1,5,6,2,3 };
  heights = { 1,1,1,8,4,4,1,1,1,1,1 };
  Solution s;
  cout << s.largestRectangleArea(heights) << endl;
  return 0;
}