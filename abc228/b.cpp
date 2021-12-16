#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){ return a > b && (a = b, true); }
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){ return a < b && (a = b, true); }
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using ld = long double;
using P = pair<int,int>;

int main() {
    int n, x;
    cin >> n >> x;
    --x;
    vector<int> a(n);
    vector<int> know(n);
    rep(i,n) {
        cin >> a[i];
        --a[i];
    }
    queue<int> que;
    que.push(x);
    while (que.size()) {
        int now = que.front(); que.pop();
        know[now] = 1;
        if (!know[a[now]]) que.push(a[now]);
    }
    int ans = 0;
    for (auto &b : know) ans += b;
    cout << ans << endl;
    return 0;
}

