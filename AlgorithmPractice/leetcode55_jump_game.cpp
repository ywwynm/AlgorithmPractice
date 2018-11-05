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
};

//int main() {
//  int arr[] = { 2,0,0 };
//  vector<int> v(arr, arr + 3);
//  Solution s;
//  cout << s.canJump(v) << endl;
//  return 0;
//}