#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, k, c;
  cin >> n >> k >> c;
  string s;
  cin >> s;
  auto getPositions = [&]() {
    vector<int> res;
    for (int i = 0; i < n && res.size() < k;) {
      if (s[i] == 'o') {
        res.push_back(i);
        i += c+1;
      } else {
        ++i;
      }
    }
    return res;
  };
  vector<int> l, r;
  l = getPositions();
  reverse(s.begin(),s.end());
  r = getPositions();
  rep(i,k) r[i] = n-1-r[i];
  reverse(s.begin(),s.end());

  vector<int> lastL(n+1, -1);
  rep(i,k) lastL[l[i]+1] = i;
  rep(i,n) {
    if (lastL[i+1] == -1) lastL[i+1] = lastL[i];
  }
  vector<int> lastR(n+1, -1);
  rep(i,k) lastR[r[i]] = i;
  for (int i = n-1; i >= 0; --i) {
    if (lastR[i] == -1) lastR[i] = lastR[i+1];
  }

  rep(i,n) {
    if (s[i] == 'x') continue;
    int li = lastL[i];
    int ri = lastR[i+1];
    int cnt = 0;
    if (li != -1) cnt += li+1;
    if (ri != -1) cnt += ri+1;
    if (li != -1 && ri != -1 && r[ri]-l[li] <= c) {
      --cnt;
    }
    if (cnt >= k) continue;
    printf("%d\n", i+1);
  }
  return 0;
}