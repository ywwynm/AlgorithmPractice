/*
  农夫知道一头牛的位置，想要抓住它。农夫和牛都位于数轴上，农夫起始位于点N(0<=N<=100000)，牛位于点K(0<=K<=100000)。农夫有两种移动方式：

  1、从X移动到X-1或X+1，每次移动花费一分钟
  2、从X移动到2*X，每次移动花费一分钟

  假设牛没有意识到农夫的行动，站在原地不动。农夫最少要花多少时间才能抓住牛？

  输入
  两个整数，N和K

  输出
  一个整数，农夫抓到牛所要花费的最小分钟数

  样例输入
  5 17

  样例输出
  4
*/

#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

bool vis[101000] = { false };

int bfs(int N, int K) {
  queue<pii> q;
  q.push(make_pair(N, 0));
  vis[N] = true;
  while (!q.empty()) {
    pii pair = q.front(); q.pop();
    int cur = pair.first, step = pair.second;
    if (cur == K) {
      return pair.second;
    }
    // vis[cur] = true; // 这会导致TLE
    if (cur - 1 >= 0 && !vis[cur - 1]) {
      vis[cur - 1] = true;
      q.push(make_pair(cur - 1, step + 1));
    }
    if (cur + 1 <= 100000 && !vis[cur + 1]) {
      vis[cur + 1] = true;
      q.push(make_pair(cur + 1, step + 1));
    }
    if (cur * 2 <= 100000 && !vis[cur * 2]) {
      vis[cur * 2] = true;
      q.push(make_pair(cur * 2, step + 1));
    }
  }
}

//int main() {
//  int N, K;
//  cin >> N >> K;
//  cout << bfs(N, K) << endl;
//  return 0;
//}