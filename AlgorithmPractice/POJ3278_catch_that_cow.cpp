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
    vis[cur] = true;
    if (cur - 1 >= 0 && !vis[cur - 1]) {
      q.push(make_pair(cur - 1, step + 1));
    }
    if (cur + 1 <= 100000 && !vis[cur + 1]) {
      q.push(make_pair(cur + 1, step + 1));
    }
    if (cur * 2 <= 100000 && !vis[cur * 2]) {
      q.push(make_pair(cur * 2, step + 1));
    }
  }
}

int main() {
  int N, K;
  cin >> N >> K;
  cout << bfs(N, K) << endl;
  return 0;
}