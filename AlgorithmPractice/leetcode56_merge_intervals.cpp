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
    if (intervals.empty() || intervals.size() == 1) return intervals;
    quickSort(intervals, 0, intervals.size() - 1);
    for (int i = intervals.size() - 1; i >= 1; i--) {
      Interval a = intervals[i - 1];
      Interval b = intervals[i];
      if (b.start <= a.end) {
        intervals.erase(intervals.begin() + i);
        intervals[i - 1].start = a.start < b.start ? a.start : b.start;
        intervals[i - 1].end = b.end;
      }
    }
    return intervals;
  }

  void quickSort(vector<Interval>& nums, int from, int to) {
    if (from >= to) return;
    int baseStart = nums[from].start;
    int base = nums[from].end;
    int i = from, j = to;
    while (i != j) {
      for (; j > i; j--) {
        if (nums[j].end < base) {
          nums[i].start = nums[j].start;
          nums[i].end = nums[j].end;
          break;
        }
      }
      for (; i < j; i++) {
        if (nums[i].end > base) {
          nums[j].start = nums[i].start;
          nums[j].end = nums[i].end;
          break;
        }
      }
    }
    nums[i].start = baseStart;
    nums[i].end = base;
    quickSort(nums, from, i - 1);
    quickSort(nums, i + 1, to);
  }

  void showIntervals(vector<Interval> intervals) {
    for (int i = 0; i < intervals.size(); i++) {
      Interval interval = intervals[i];
      cout << "[" << interval.start << ", " << interval.end << "]" << " ";
    }
    cout << endl;
  }
};

//int main() {
//   Solution s;
//   Interval i1(2, 3);
//   Interval i2(4, 5);
//   Interval i3(6, 7);
//   Interval i4(8, 9);
//   Interval i5(1, 10);
//   //Interval i1(0, 2);
//   //Interval i2(1, 4);
//   //Interval i3(3, 5);
//   vector<Interval> v;
//   v.push_back(i1);
//   v.push_back(i2);
//   v.push_back(i3);
//   v.push_back(i4);
//   v.push_back(i5);
//   vector<Interval> res = s.merge(v);
//   s.showIntervals(res);
//  return 0;
//}