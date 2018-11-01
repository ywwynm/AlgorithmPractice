#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int size = nums.size();
    if (size == 1) {
      return target == nums[0] ? 0 : -1;
    }
    int left = 0, right = size - 1;
    while (left < right) {
      if (left == right - 1) {
        if (nums[left] == target) return left;
        if (nums[right] == target) return right;
        return -1;
      }
      int mid = (left + right) / 2;
      if (nums[mid] == target) {
        return mid;
      }
      if (nums[mid] < nums[left]) { // pivot is inside left part
        if (target < nums[mid]) {
          right = mid;
        } else if (target > nums[right]) {
          right = mid;
        } else {
          left = mid;
        }
      } else { // pivot is inside right part
        if (target > nums[mid]) {
          left = mid;
        } else if (target < nums[left]) {
          left = mid;
        } else {
          right = mid;
        }
      }
    }
    return -1;
  }
};

int main() {
  int nums_arr[] = { 4,5,6,7,0,1,2 };
  vector<int> nums(nums_arr, nums_arr + 7);
  Solution s;
  cout << s.search(nums, 10) << endl;
  return 0;
}