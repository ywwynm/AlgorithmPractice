#include <iostream>
#include <vector>

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    const int size = heights.size();
    vector<vector<int>> dp(size, vector<int>(2));
    dp[0][0] = 0;
    dp[0][0] = 1;
    for (int i = 0; i < size - 1; i++) {
      int x = dp[i][1];
      int smallest_height = heights[x];
      int cur_height = heights[i + 1];
      if (cur_height >= smallest_height) {
        
      } else {
        
      }
    }
  }
};

using namespace std;

int main() {
  vector<int> heights = { 2,1,5,6,2,3 };
  Solution s;
  cout << s.largestRectangleArea(heights) << endl;
  return 0;
}