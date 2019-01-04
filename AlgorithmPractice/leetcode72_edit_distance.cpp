#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

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
      int min = 0x3f3f3f3f;
      for (int k = i - 1; k >= 0; k--) {
        int tmp = dp[k][j] + i - k;
        if (tmp < min) {
          min = tmp;
        }
      }
      if (min == i - j || min == j - i) {
        dp[i][j] = min;
        continue;
      }
      for (int k = j - 1; k >= 0; k--) {
        int tmp = dp[i][k] + j - k;
        if (tmp < min) {
          min = tmp;
        }
      }
      if (min == i - j || min == j - i) {
        dp[i][j] = min;
        continue;
      }
      int tmp = 0x3f3f3f3f;
      int add = word1[i] == word2[j] ? 0 : 1;
      if (i >= 1 && j >= 1) {
        tmp = dp[i - 1][j - 1] + add;
      } else if (i >= 1) {
        tmp = i + add;
      } else if (j >= 1) {
        tmp = j + add;
      } else {
        tmp = add;
      }
      if (tmp < min) {
        min = tmp;
      }
      dp[i][j] = min;
      // cout << "dp[" << i << "][" << j << "]: " << dp[i][j] << endl;
    }
    return dp[len1 - 1][len2 - 1];
  }

  int minDistance2(string word1, string word2) {
    const int len1 = word1.length(), len2 = word2.length();
    if (len1 == 0 || len2 == 0) {
      return len1 > len2 ? len1 : len2;
    }
    map<char, vector<int>> map1, map2;
    for (int i = 0; i < len1; i++) {
      char c = word1[i];
      if (map1.find(c) == map1.end()) {
        map1[c] = vector<int>();
      }
      map1[c].push_back(i);
    }
    for (int i = 0; i < len2; i++) {
      char c = word2[i];
      if (map2.find(c) == map2.end()) {
        map2[c] = vector<int>();
      }
      map2[c].push_back(i);
    }
    vector<vector<int>> dp(len1, vector<int>(len2, 0x3f3f3f3f));
    dp[0][0] = word1[0] == word2[0] ? 0 : 1;
    for (int i = 0; i < len1; i++) for (int j = 0; j < len2; j++) {
      int min = 0x3f3f3f3f;
      char c1 = word1[i], c2 = word2[j];
      if (map1.find(c2) != map1.end()) {
        vector<int> indices = map1[c2];
        for (auto k : indices) {
          if (k >= i) break;
          int tmp = dp[k][j] + i - k;
          if (tmp < min) {
            min = tmp;
          }
        }
      }
      if (map2.find(c1) != map2.end()) {
        vector<int> indices = map2[c1];
        for (auto k : indices) {
          if (k >= j) break;
          int tmp = dp[i][k] + j - k;
          if (tmp < min) {
            min = tmp;
          }
        }
      }
      int tmp = 0x3f3f3f3f;
      int add = word1[i] == word2[j] ? 0 : 1;
      if (i >= 1 && j >= 1) {
        tmp = dp[i - 1][j - 1] + add;
      } else if (i >= 1) {
        tmp = i + add;
      } else if (j >= 1) {
        tmp = j + add;
      } else {
        tmp = add;
      }
      if (tmp < min) {
        min = tmp;
      }
      dp[i][j] = min;
      // cout << "dp[" << i << "][" << j << "]: " << dp[i][j] << endl;
    }
    return dp[len1 - 1][len2 - 1];
  }

  int minDistance3(string word1, string word2) {
    const int INF = 0x3f3f3f3f;
    const int len1 = word1.length(), len2 = word2.length();
    if (len1 == 0 || len2 == 0) {
      return len1 > len2 ? len1 : len2;
    }
    vector<vector<int>> dp(len1, vector<int>(len2, 0x3f3f3f3f));
    dp[0][0] = word1[0] == word2[0] ? 0 : 1;
    for (int i = 0; i < len1; i++) for (int j = 0; j < len2; j++) {
      if (i == 0 && j == 0) continue;
      char c1 = word1[i], c2 = word2[j];
      int x = i >= 1 ? dp[i - 1][j] + 1 : INF;
      int y = j >= 1 ? dp[i][j - 1] + 1 : INF;
      int z;
      if (i >= 1 && j >= 1) {
        z = dp[i - 1][j - 1];
      } else if (i >= 1) {
        z = i;
      } else if (j >= 1) {
        z = j;
      } else {
        z = INF;
      }
      if (c1 != c2) z++;
      int tmp = x < y ? x : y;
      dp[i][j] = tmp < z ? tmp : z;
    }
    return dp[len1 - 1][len2 - 1];
  }

  int minDistanceBestFromInternet(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
      dp[i][0] = i;
    for (int j = 1; j <= n; j++)
      dp[0][j] = j;
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (word1[i - 1] == word2[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
      }
    }
    return dp[m][n];
  }
};

//int main() {
//  Solution s;
//  cout << s.minDistanceBestFromInternet("a", "ab") << endl;
//  cout << s.minDistanceBestFromInternet("intention", "execution") << endl;
//  cout << s.minDistanceBestFromInternet("a", "b") << endl;
//  cout << s.minDistanceBestFromInternet("plasma", "altruism") << endl;
//  cout << s.minDistanceBestFromInternet("pl", "las") << endl;
//  cout << s.minDistanceBestFromInternet("abc", "apc") << endl;
//  cout << s.minDistanceBestFromInternet("horse", "ros") << endl;
//  cout << s.minDistanceBestFromInternet("a", "bc") << endl;
//  cout << s.minDistanceBestFromInternet("a", "bac") << endl;
//  return 0;
//}