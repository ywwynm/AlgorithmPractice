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
    vector<vector<int>> dp(len1, vector<int>(len2, 0));
    dp[0][0] = word1[0] == word2[0] ? 0 : 1;
    for (int i = 0; i < len1; i++) for (int j = 0; j < len2; j++) {
      if (i == 0 && j == 0) continue;
      char c1 = word1[i], c2 = word2[j];
      if (i == j) {
        if (c1 == c2) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          int a = dp[i - 1][j - 1] + 1;
          int b = dp[i - 1][j] + 1;
          int c = dp[i][j - 1] + 1;
          int abMin = a < b ? a : b;
          dp[i][j] = abMin < c ? abMin : c;
        }
      } else if (i > j) {
        if (j == 0) {
          dp[i][j] = c1 == c2 ? i - j : dp[i - 1][j] + 1;
        } else {
          int min = 0x3f3f3f3f;
          for (int k = j - 1; k >= 0; k--) {
            int tmp = dp[i][k] + j - k;
            if (tmp < min) min = tmp;
          }
          dp[i][j] = min;
        }
      } else {
        if (i == 0) {
          dp[i][j] = c1 == c2 ? j - i : dp[i][j - 1] + 1;
        } else {
          int min = 0x3f3f3f3f;
          for (int k = i - 1; k >= 0; k--) {
            int tmp = dp[k][j] + i - k;
            if (tmp < min) min = tmp;
          }
          dp[i][j] = min;
        }
      }
      cout << "dp[" << i << "][" << j << "]: " << dp[i][j] << endl;
    }
    return dp[len1 - 1][len2 - 1];
  }
};

int main() {
  Solution s;
  //cout << s.minDistance("plasma", "lasmabcd") << endl;
  cout << s.minDistance("pl", "las") << endl;
  return 0;
}