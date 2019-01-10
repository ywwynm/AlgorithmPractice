#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

  void print_vector(vector<int> nums) {
    for (auto x : nums) {
      cout << x << " ";
    }
    cout << endl;
  }

  void sortColors(vector<int>& nums) {
    const int size = nums.size();
    int front = 0, end = size - 1, temp;
    for (int i = 0; i <= end; ) {
      int cur = nums[i];
      // cout << "i: " << i << ", cur: " << cur << ", front: " << front << ", end: " << end << endl;
      if (cur == 0) {
        temp = nums[front];
        nums[front] = cur;
        nums[i] = temp;
        front++;
        if (temp == 0) i++;
      } else if (cur == 1) {
        i++;
      } else {
        temp = nums[end];
        nums[end] = cur;
        nums[i] = temp;
        end--;
      }
      // print_vector(nums);
    }
  }
};

int main() {
  int arr[] = { 1,1,2,1,1 };
  vector<int> v(arr, arr + 5);
  Solution s;
  s.sortColors(v);
  s.print_vector(v);
  
  return 0;
}