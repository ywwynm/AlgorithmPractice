#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  void printVector(vector<int> nums) {
    for (auto i : nums) {
      cout << i << " ";
    }
    cout << endl;
  }

  int removeDuplicates(vector<int>& nums) {
    int numsSize = nums.size();
    if (numsSize <= 1) return numsSize;
    int ret = 1;
    int curNum = nums[0], rec = 1, totalExtra = 0;
    for (int i = 1; i < numsSize - totalExtra; i++) {
      if (nums[i] == curNum) {
        rec++;
        if (rec > 2) {
          int extraCount = 1;
          for (int j = i + 1; j < numsSize - totalExtra; j++) {
            if (nums[j] != curNum) break;
            extraCount++;
          }
          totalExtra += extraCount;
          // cout << rec << ", " << ret << ", " << i << ", " << extraCount << endl;
          for (int j = i; j < numsSize - totalExtra; j++) {
            nums[j] = nums[j + extraCount];
          }
          // printVector(nums);
          rec = 0;
          i--; // there will be another i++ in the end, so i remains
          curNum = nums[i - 1];
        } else {
          ret++;
        }
      } else {
        curNum = nums[i];
        rec = 1;
        ret++;
      }
    }
    return ret;
  }
};

//int main() {
//  int arr[] = { 2,2,2,3 };
//  vector<int> nums(arr, arr + 4);
//  Solution s;
//  cout << s.removeDuplicates(nums) << endl;
//  s.printVector(nums);
//  return 0;
//}