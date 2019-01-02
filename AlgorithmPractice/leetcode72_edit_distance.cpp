#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    const int len1 = word1.length(), len2 = word2.length();
    if (len1 == 0 || len2 == 0) {
      return len1 > len2 ? len1 : len2;
    }
    vector<vector<int>> dp(len1, vector<int>(len2, 0x3f3f3f3f));
    dp[0][0] = word1[0] == word2[0] ? 0 : 1;
    for (int i = 0; i < len1; i++) for (int j = 0; j < len2; j++) {
      if (i == 0 && j == 0) continue;
      int min = 0x3f3f3f3f;
      for (int k = i - 1; k >= 0; k--) {
        int tmp = dp[k][j] + i - k;
        if (tmp < min) min = tmp;
      }
      for (int k = j - 1; k >= 0; k--) {
        int tmp = dp[i][k] + j - k;
        if (tmp < min) min = tmp;
      }
      int tmp = 0x3f3f3f3f;
      int add = word1[i] == word2[j] ? 0 : 1;
      if (i >= 1 && j >= 1) {
        tmp = dp[i - 1][j - 1] + add;
      } else if (i >= 1) {
        tmp = i + add;
      } else if (j >= 1) {
        tmp = j + add;
      }
      if (tmp < min) min = tmp;
      dp[i][j] = min;
      // cout << "dp[" << i << "][" << j << "]: " << dp[i][j] << endl;
    }
    return dp[len1 - 1][len2 - 1];
  }
};

int main() {
  Solution s;
  cout << s.minDistance("plasma", "altruism") << endl;
  cout << s.minDistance("pl", "las") << endl;
  cout << s.minDistance("abc", "apc") << endl;
  cout << s.minDistance("intention", "execution") << endl;
  cout << s.minDistance("horse", "ros") << endl;
  cout << s.minDistance("a", "bc") << endl;
  cout << s.minDistance("a", "bac") << endl;
  return 0;
}