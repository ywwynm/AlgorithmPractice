#include <vector>
#include <iostream>

using namespace std;

void print_vector(vector<int> nums) {
  for (auto i : nums) {
    cout << i << " ";
  }
  cout << endl;
}

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (k >= 0) {
      if (i >= 0 && j >= 0) {
        int n1 = nums1[i], n2 = nums2[j];
        if (n1 <= n2) {
          nums1[k] = n2;
          j--;
        } else {
          nums1[k] = n1;
          i--;
        }
      } else if (i >= 0) {
        nums1[k] = nums1[i--];
      } else if (j >= 0) {
        nums1[k] = nums2[j--];
      }
      k--;
      cout << i << ", " << j << ", " << k << endl;
    }
  }
};

int main() {
  Solution s;
  vector<int> nums1 = { 7, 8, 9, 0, 0, 0, 0, 0, 0 };
  vector<int> nums2 = { 2, 5, 6 };
  s.merge(nums1, 3, nums2, 3);
  print_vector(nums1);
  cout << nums1.size() << endl;
  return 0;
}