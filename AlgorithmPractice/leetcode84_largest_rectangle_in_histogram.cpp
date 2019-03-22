#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int maxArea = 0;
    const int size = heights.size();
    vector<int> dp;
    for (int i = 0; i < size; i++) {
      for (int j = i; j < size; j++) {
        int area;
        if (i == j) {
          dp.push_back(j);
          area = heights[i];
        } else {
          int x = dp[j - i - 1];
          int newx = heights[j] < heights[x] ? j : x;
          dp.push_back(newx);
          area = heights[newx] * (j - i + 1);
        }
        // cout << i << ", " << j << " -> minHeightIdx: " << dp[j - i] << ", area: " << area << endl;
        if (area > maxArea) maxArea = area;
      }
      dp.clear();
    }
    return maxArea;
  }
};

//int main() {
//  vector<int> heights = { 2,1,5,6,2,3 };
//  // heights = { 1,1,1,8,4,4,1,1,1,1,1 };
//  Solution s;
//  cout << s.largestRectangleArea(heights) << endl;
//  return 0;
//}