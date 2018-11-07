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
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    const int size = intervals.size();
    if (size == 0) {
      intervals.push_back(newInterval);
      return intervals;
    }
    if (newInterval.start <= intervals[0].start) {
      intervals.insert(intervals.begin(), newInterval);
    } else if (newInterval.start >= intervals[size - 1].start) {
      intervals.push_back(newInterval);
    } else {
      int start = 0, end = size - 1;
      int mid = (start + end) / 2;
      int idx = mid;
      while (mid != start && mid != end) {
        Interval it = intervals[mid];
        if (newInterval.start <= it.start) {
          if (newInterval.start >= intervals[mid - 1].start) {
            idx = mid - 1;
            break;
          } else {
            end = mid;
          }
        } else if (newInterval.start >= it.start) {
          if (newInterval.start <= intervals[mid + 1].start) {
            idx = mid;
            break;
          } else {
            start = mid;
          }
        }
      }
      intervals.insert(intervals.begin() + idx + 1, newInterval);
    }
    //showIntervals(intervals);
    for (int i = 0; i < intervals.size() - 1; ) {
      Interval a = intervals[i];
      Interval b = intervals[i + 1];
      //cout << "a: (" << a.start << ", " << a.end << "); b: (" << b.start << ", " << b.end << ")" << endl;
      if (a.end >= b.start) {
        intervals.erase(intervals.begin() + i);
        intervals[i].start = a.start;
        intervals[i].end = a.end > b.end ? a.end : b.end;
      } else {
        i++;
      }
    }
    return intervals;
  }

  void showIntervals(vector<Interval> intervals) {
    for (int i = 0; i < intervals.size(); i++) {
      Interval interval = intervals[i];
      cout << "[" << interval.start << ", " << interval.end << "]" << " ";
    }
    cout << endl;
  }
};

int main() {
  Solution s;
  Interval i1(1, 2);
  Interval i2(3, 5);
  Interval i3(6, 7);
  Interval i4(8, 10);
  Interval i5(12, 16);
  vector<Interval> v;
  v.push_back(i1);
  v.push_back(i2);
  v.push_back(i3);
  v.push_back(i4);
  v.push_back(i5);
  vector<Interval> res = s.insert(v, Interval(4, 8));
  s.showIntervals(res);
  return 0;
}