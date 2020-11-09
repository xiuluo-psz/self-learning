#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class MedianFinder {
public:
  // 大顶堆存小数(左)
  priority_queue<int, vector<int>, less<int>> maxpq;
  // 小顶堆存大数（右）
  priority_queue<int, vector<int>, greater<int>> minpq;
  void addNum(int num) {
    // 同大小存小顶堆（右）
    if (maxpq.size() == minpq.size()) {
      maxpq.push(num);
      minpq.push(maxpq.top());
      maxpq.pop();
    } else {
      minpq.push(num);
      maxpq.push(minpq.top());
      minpq.pop();
    }
  }
  double findMedian() {
    int left = maxpq.top();
    int right = minpq.top();
    return maxpq.size() == minpq.size() ? (left + right) * 0.5 : right;
  }
};

int main(int argc, const char *argv[]) {
  MedianFinder s;
  s.addNum(3);
  s.addNum(4);
  s.addNum(5);
  s.addNum(1);
  s.addNum(2);
  s.addNum(7);
  cout << s.findMedian();
  return 0;
}