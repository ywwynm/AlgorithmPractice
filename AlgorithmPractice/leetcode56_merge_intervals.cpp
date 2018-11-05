#include <vector>
#include <iostream>

using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  vector<Interval> merge(vector<Interval>& intervals) {
    
  }

  void quickSort(vector<int>& nums, int from, int to) {
    if (from >= to) return;
    int base = nums[from];
    int i = from, j = to;
    cout << i << ", " << j << endl;
    while (i != j) {
      for (; j > i; j--) {
        if (nums[j] < base) {
          nums[i] = nums[j];
          break;
        }
      }
      for (; i < j; i++) {
        if (nums[i] > base) {
          nums[j] = nums[i];
          break;
        }
      }
    }
    nums[i] = base;
    quickSort(nums, from, i - 1);
    quickSort(nums, i + 1, to);
  }
};

int main() {
  // Interval i1(1, 3);
  // Interval i2(2, 6);
  // Interval i3(8, 10);
  // Interval i4(15, 18);
  // vector<Interval> v;
  // v.push_back(i1);
  // v.push_back(i2);
  // v.push_back(i3);
  // v.push_back(i4);
  // Solution s;
  // vector<Interval> res = s.merge(v);
  // for (auto i: res) {
  //   cout << "[" << i.start << ", " << i.end << "]" << "\r";
  // }
  int arr[] = {0,0,1,0,0};
  vector<int> v(arr, arr + 5);
  Solution s;
  s.quickSort(v, 0, 4);
  for (auto i: v) {
    cout << i << "\r";
  }
  cout << endl;
  return 0;
}