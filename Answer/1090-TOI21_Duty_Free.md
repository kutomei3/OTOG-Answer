#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000005;
int par[maxn];
int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}
void join(int x, int y) {
  int px = find(x);
  int py = find(y);
  if (px == py) return;
  par[px] = py;
}

int minimum_bag_rearrangement_time(std::vector<int> vec) {
  int ct = 0;
  int n = vec.size();
  iota(par, par + maxn, 0);
  vector<int> use;
  vector<int> all(n + 1, false);
  for (int i = 0; i < n;) {
    int pi = find(vec[i]);
    if (pi == 0) {
      ct++;
      for (auto& p : use) par[p] = p;
      use.clear();
    } else {
      use.push_back(pi);
      join(pi, pi - 1);
      i++;
    }
  }
  return ct;
}