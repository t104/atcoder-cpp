#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> pre(n,-1);
  int ans = n;
  rep(i,n) {
    int a;
    cin >> a;
    if (i-pre[a] > m) ans = min(ans, a);
    pre[a] = i;
  }
  rep(i,n) if (n-pre[i] > m) ans = min(ans, i);
  cout << ans << endl;
  return 0;
}