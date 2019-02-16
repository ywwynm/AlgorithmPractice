#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    if (s.empty()) return 0;
    stack<char> st;
    st.push(s[0]);
    int count = 0;
    for (int i = 1; i < s.length(); i++) {
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
    return count;
  }
};

int main() {
  Solution s;
  // ()(() should return 2
  cout << s.longestValidParentheses("()(()") << endl;
  return 0;
}