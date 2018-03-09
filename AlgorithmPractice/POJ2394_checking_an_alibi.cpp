#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int MAX_NODE = 1000;
const int MAX_EDGE = 1000000;

struct edge {
  int u, v, w, next;
} E[MAX_EDGE];

int edge_count = 0;
int nodes[MAX_NODE];

void add_edge(int u, int v, int w) {
  E[edge_count] = edge { u, v, w, nodes[u] };
  nodes[u] = edge_count++;
}

int spfa(int S, int T) {
  int dis[MAX_NODE];
  bool inq[MAX_NODE];
  memset(dis, 0x3f, sizeof(dis));
  memset(inq, false, sizeof(inq));
  dis[S] = 0;
  queue<int> q;
  q.push(S);
  inq[S] = true;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    inq[u] = false;
    for (int i = nodes[u]; i != -1; i = E[i].next) {
      int v = E[i].v;
      if (dis[v] > dis[u] + E[i].w) {
        dis[v] = dis[u] + E[i].w;
        if (!inq[v]) q.push(v);
      }
    }
  }
  return dis[T];
}

// int main() {
//   memset(nodes, -1, sizeof(nodes));
//   int F, P, C, M;
//   cin >> F >> P >> C >> M;
//   for (int i = 0; i < P; i++) {
//     int F1, F2, T;
//     cin >> F1 >> F2 >> T;
//     add_edge(F1, F2, T);
//     add_edge(F2, F1, T);
//   }
//   int count = 0;
//   vector<int> cows;
//   for (int i = 0; i < C; i++) {
//     int loc; cin >> loc;
//     if (spfa(loc, 1) <= M) {
//       count++;
//       cows.push_back(i + 1);
//     }
//   }
//   cout << count << endl;
//   for (int i = 0; i < count; i++) cout << cows[i] << endl;
//   return 0;
// }