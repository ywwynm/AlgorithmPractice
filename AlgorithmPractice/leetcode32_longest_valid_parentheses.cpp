#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int rec(string s, int l, int r, vector<vector<int>> &dp) {
    int max = dp[l][r];
    for (int k = l + 1; k < r; k++) {
      if (dp[l][k] == -1) {
        dp[l][k] = rec(s, l, k, dp);
      }
      int left = dp[l][k];

      if (dp[k][r] == -1) {
        dp[k][r] = rec(s, k, r, dp);
      }
      int right = dp[k][r];

      stack<char> st;
      st.push(s[l]);
      int count = 0;
      for (int i = l + 1; i <= r; i++) {
        char c = s[i];
        if (st.empty()) {
          st.push(c);
        } else if (st.top() == '(' && c == ')') {
          count += 2;
          st.pop();
        } else {
          st.push(c);
        }
      }

      int curMax;
      if (st.empty()) {
        int temp = left + right;
        curMax = count < temp ? temp : count;
      } else {
        curMax = left < right ? right : left;
      }

      cout << l << ", " << r << ": curMax -> " << curMax << endl;

      if (max < curMax) max = curMax;
    }

    dp[l][r] = max;
    return max;
  }

  int longestValidParentheses(string s) {
    if (s.empty()) return 0;
    const int sLen = s.length();
    vector<vector<int>> dp(sLen, vector<int>(sLen, -1));
    for (int i = 0; i < sLen; i++) {
      for (int j = i; j < sLen; j++) {
        if (i == j) {
          dp[i][j] = 0;
        } else if (j == i + 1) {
          if (s[i] == '(' && s[j] == ')') {
            dp[i][j] = 2;
          } else {
            dp[i][j] = 0;
          }
        }
      }
    }

    return rec(s, 0, sLen - 1, dp);
  }
};

int main() {
  Solution s;
  // ()(() should return 2
  // cout << s.longestValidParentheses("(())") << endl;
  cout << s.longestValidParentheses(")(()))()(())()()()()(()(()))()())(()()(())()(((()()(()((()(()()((()()))(())())(()(())(()(())(()(()))(()))()()(((()())(()()(()((())))))(()(()())(()))))))())))()())()(())(((()(()))()()(()(((()))()") << endl;
  return 0;
}