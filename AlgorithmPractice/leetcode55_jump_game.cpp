#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

  bool canJump(vector<int>& nums) {
    const int size = nums.size();
    if (size == 1) return true;
    for (int i = 0; i < size; i++) {
      if (nums[i] == 0) {
        bool canStride = false;
        for (int j = i - 1; j >= 0 && !canStride; j--) {
          if (j + nums[j] > i) {
            canStride = true;
          } else if (j + nums[j] == i && i == size - 1) {
            canStride = true;
          }
        }
        if (!canStride) return false;
      }
    }
    return true;
  }

  bool myBetter(vector<int>& nums) {
    const int size = nums.size();
    if (size == 1) return true;
    for (int i = size - 1; i >= 0; ) {
      if (nums[i] == 0) {
        bool canStride = false;
        for (int j = i - 1; j >= 0 && !canStride; j--) {
          if (j + nums[j] > i) {
            canStride = true;
            i = j - 1;
          } else if (j + nums[j] == i && i == size - 1) {
            canStride = true;
            i = j - 1;
          }
        }
        if (!canStride) return false;
      } else i--;
    }
    return true;
  }

  bool myBetter2(vector<int>& nums) {
    const int size = nums.size();
    if (size == 1) return true;
    int furthest = -1;
    for (int i = 0; i < size - 1; i++) {
      if (nums[i] == 0 && furthest <= i) return false;
      if (i + nums[i] > furthest) {
        furthest = i + nums[i];
        if (furthest >= size - 1) return true; // actually we don't need this optimization
      }
    }
    return furthest >= size - 1;
  }
};

int main() {
  int arr[] = { 3,2,1,0,4 };
  vector<int> v(arr, arr + 3);
  Solution s;
  cout << s.myBetter2(v) << endl;
  return 0;
}