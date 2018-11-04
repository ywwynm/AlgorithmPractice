#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    vector<vector<bool>> dp;
    const int size = nums.size();
    for (int i = 0; i < size; i++) {
      vector<bool> tmp;
      for (int j = 0; j < size; j++) {
        tmp.push_back(false);
      }
      dp.push_back(tmp);
    }
    dp[size - 1][size - 1] = true;
    for (int i = size - 2; i >= 0; i--) {
      for (int j = i + 1; j < size && !dp[i][size - 1]; j++) {
        if (i + nums[i] >= j && dp[j][size - 1]) {
          dp[i][size - 1] = true;
        }
      }
    }
    return dp[0][size - 1];
  }
};

int main() {
  int arr[] = { 3,2,1,0,4 };
  vector<int> v(arr, arr + 5);
  Solution s;
  cout << s.canJump(v) << endl;
  return 0;
}