#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:

  string vector_to_set_elem(vector<int> v) {
    sort(v.begin(), v.end());
    string s = "";
    for (auto i : v) {
      s += to_string(i) + " ";
    }
    return s;
  }

  void combine_recursive(vector<int>& nums, vector<vector<int>>& ret, vector<int>& v, set<string>& elems, int start, int idx, int k) {
    if (v.size() == k) {
      string set_elem = vector_to_set_elem(v);
      if (elems.find(set_elem) != elems.end()) {
        return;
      }
      elems.insert(set_elem);
      ret.push_back(v);
      return;
    }

    for (int i = start; i <= nums.size() - k + idx; i++) {
      v.push_back(nums[i]);
      combine_recursive(nums, ret, v, elems, i + 1, idx + 1, k);
      v.pop_back();
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ret;
    vector<int> v;
    set<string> elems;
    const int size = nums.size();
    for (int i = 1; i <= size; i++) {
      combine_recursive(nums, ret, v, elems, 0, 0, i);
    }
    ret.push_back(vector<int>()); // empty set
    return ret;
  }
};

int main() {
  Solution s;
  int arr[] = { 4, 4, 4, 1, 4 };
  vector<int> nums(arr, arr + 5);
  vector<vector<int>> subsets = s.subsetsWithDup(nums);
  for (auto v : subsets) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}