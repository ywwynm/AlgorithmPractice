#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  void combine_recursive(vector<int>& nums, vector<vector<int>> &ret, vector<int> &v, int start, int idx, int k) {
    if (v.size() == k) {
      ret.push_back(v);
      return;
    }
    for (int i = start; i <= nums.size() - k + idx; i++) {
      v.push_back(nums[i]);
      combine_recursive(nums, ret, v, i + 1, idx + 1, k);
      v.pop_back();
    }
  }

  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ret;
    vector<int> v;
    const int size = nums.size();
    for (int i = 1; i <= size; i++) {
      combine_recursive(nums, ret, v, 0, 0, i);
    }
    ret.push_back(vector<int>());
    return ret;
  }
};

int main() {
  Solution s;
  int arr[] = { 1, 2, 3, 5 };
  vector<int> nums(arr, arr + 4);
  vector<vector<int>> subsets = s.subsets(nums);
  for (auto v : subsets) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}