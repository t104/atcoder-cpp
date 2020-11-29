#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
using T = tuple<int, int, int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;
const int MX = 50;
const int C = MX / 2;
const int C2 = C / 2;
const int di[] = {1, 1, -1, -1};
const int dj[] = {1, -1, -1, 1};

int dp[MX][MX][4];

map<P, int> dir {
    {make_pair(1,1), 0},
    {make_pair(-1,1), 1},
    {make_pair(-1,-1), 2},
    {make_pair(1,-1), 3}
};

int dist(P a, P b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void printp(P a) {
    cout << a.first << ' ' << a.second << endl;
}

void solve() {
    P a, b, c;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;

    if (dist(a,b) == 2) swap(b,c);
    if (dist(b,c) == 2) swap(a,c);
    P d;
    d.first = a.first + b.first - c.first;
    d.second = a.second + b.second - c.second;
    int v = 0;
    if (c.first < d.first && c.second < d.second) v = 0;
    if (c.first < d.first && c.second > d.second) v = 1;
    if (c.first > d.first && c.second > d.second) v = 2;
    if (c.first > d.first && c.second < d.second) v = 3;
    

}

int main() {
    rep(i,MX) rep(j,MX) rep(k,4) dp[i][j][k] = INF;
    queue<T> que;
    auto push = [&](int i, int j, int k, int x) {
        if (0 < i || 0 < j || MX <= i || MX <= j) return;
        if (dp[i][j][k] != INF) return;
        dp[i][j][k] = x;
        que.emplace(i, j, k);
    };
    push(C,C,0,0);
    while (!que.empty()) {
        int i, j, k;
        tie(i, j, k) = que.front(); que.pop();
        int nd = dp[i][j][k] + 1;
        for (int s = 1; s <= 3; ++s) {
            int nk = (k+s) % 4;
            push(i + (di[k] + di[nk^2]) / 2, j + (dj[k] + dj[nk^2]) / 2, nk, nd);
            if (s&1) push(i + (di[k] + di[nk]) / 2, j + (dj[k] + dj[nk]) / 2, k^2, nd);
        }
        push(i, j, k^1, nd);
        push(i, j, k^3, nd);
    }

    int t;
    cin >> t;
    rep(i,t) {
        solve();
    }
    return 0;
}