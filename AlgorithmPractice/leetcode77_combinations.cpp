#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

  void combine_recursive(vector<vector<int>> &ret, vector<int> &v, int start, int idx, int n, int k) {
    if (v.size() == k) {
      ret.push_back(v);
      return;
    }
    for (int i = start + 1; i <= n - k + idx + 1; i++) {
      v.push_back(i);
      combine_recursive(ret, v, i, idx + 1, n, k);
      v.pop_back();
    }
  }

  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ret;

    vector<int> v;
    combine_recursive(ret, v, 0, 0, n, k);
    /*for (int i = 1; i <= n - k + 1; i++) {
    }*/
    return ret;
  }
};

int main() {
  Solution s;
  vector<vector<int>> ret = s.combine(5, 3);
  for (auto v : ret) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}