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

  bool isValid(string s) {
    stack<char> st;
    st.push(s[0]);
    for (int i = 1; i < s.length(); i++) {
      char c = s[i];
      if (st.empty()) {
        st.push(c);
      } else if (st.top() == '(' && c == ')') {
        st.pop();
      } else {
        st.push(c);
      }
    }
    return st.empty();
  }

  int solution2(string s) {
    if (s.empty()) return 0;
    vector<int> leftBrackets, rightBrackets;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(') leftBrackets.push_back(i);
      else rightBrackets.push_back(i);
    }

    int max = 0;
    for (int i = 0; i < leftBrackets.size(); i++) {
      int l = leftBrackets[i];
      for (int j = rightBrackets.size() - 1; j >= 0; j--) { // the order may be changed
        int r = rightBrackets[j];
        if (r <= l || r - l + 1 <= max) break;
        int substrLen = r - l + 1;
        if (isValid(s.substr(l, substrLen))) {
          if (max < substrLen) {
            max = substrLen;
          }
          break;
        }
      }
    }
    return max;
  }

  int solutionDP(string s) {
    if (s.empty()) return 0;
    const int sLen = s.length();
    vector<int> dp(sLen, 0);
    int ret = 0;
    for (int i = 1; i < sLen; i++) {
      char c = s[i];
      if (c == ')') {
        char l = s[i - 1];
        if (i == 1) {
          dp[i] = l == '(' ? 2 : 0;
        } else {
          if (l == '(') {
            dp[i] = dp[i - 2] + 2;
          } else {
            int idx = i - dp[i - 1] - 1;
            if (idx >= 0 && s[idx] == '(') {
              dp[i] = dp[i - 1] + 2;
              if (idx - 1 >= 0) {
                dp[i] += dp[idx - 1];
              }
            }
          }
        }
      }
      if (dp[i] > ret) {
        ret = dp[i];
      }
    }
    return ret;
  }
};

int main() {
  Solution s;
  // ()(() should return 2
  //cout << s.solutionDP("()(())") << endl;
  cout << s.solutionDP("()())") << endl;
  //cout << s.solutionDP(")(()))()(())()()()()(()(()))()())(()()(())()(((()()(()((()(()()((()()))(())())(()(())(()(())(()(()))(()))()()(((()())(()()(()((())))))(()(()())(()))))))())))()())()(())(((()(()))()()(()(((()))()") << endl;
  cout << s.solutionDP("(()(()()()(()())()(()()))()()())()(((()())((())(()()((()((((())(())()()(())()(()(()(())))))))(()()()))()()))))))(()())))((())())))()(((()(()))())((())))(())(((()()))))())))((()((()()(()))())(()))(())((())()(((()(((()))))()))()()())()()()(()(()(()()()(()(())(())))())()))())(())((())(()((((())((())((())(()()(((()))(()(((())())()(())))(()))))))(()(()(()))())(()()(()(((()()))()(())))(()()(())))))(()(()()())))()()())))))((())(()()(((()(()()))(())))(((()))())())())(((()((()((()())((()))(()()((()(())())(()))()())())))))()(()())))()()))(((()(()))((()((((())((())))((())()()))())()(((()()(((()))))))(((()))()(()(((())(())()()()))))()))()))))()(()))()()()))))()(()))()()(()())))(()))()())(())()())(())()()))(()())))((()())))())))))((()))())()()))))()))(((())(())()))()()((()))(((()))))((()((()))(())(((()))()()()())())())))(()(((())()())(())(((()()((())()))(()()(((())))((()(((()))(((((()(((())())))(())(()()((()(()(())())(((((())((()()))())(()())))()()()(()(((((((())))(()()()()((()(((())())())())))())())())))()((((())(((()()()())()))()()(()(()()))()))(())(()())))))()())()())))()()(())))))))((())()()(((()))()))())))))((()())((()())(((())()())()))(()(()()(((()(())()))()())()()(())()(()))))()))()()))))(())(()()(())((()))(()))((())))))(())))()))(()()(())))())()((())()))((()()(()())()()(()))())(((())()(((()((())()(()()()((()(()())(()())())((((())))())())))(()))(((())((()))))((()()(((())((())()()()))((()())()()())())))))((((()((()())))(())(())()()()(((((())())()()()(())())()((()(()())(((())((((()((()(((()))(()()))())()()(()(()(())))()))())))(()()(()))))))(()()())()()))()(())()(") << endl;
  //cout << s.solutionDP("(())") << endl;
  return 0;
}