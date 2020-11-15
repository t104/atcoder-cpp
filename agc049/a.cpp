#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

int n;
vector<vector<int>> G;

void dfs(int now, int prev, vector<int> &r) {
    r.push_back(now);
    for (auto next : G.at(now)) {
        if (next == prev) continue;
        dfs(next, now, r);
    }
}


int main() {
    cin >> n;
    G.assign(n, vector<int>(n));
    
    rep(i,n) {
        string s;
        cin >> s;
        rep(j,n) {
            if (s.at(j) == '1') {
                G.at(i).at(j) = 1;
            }
        }
    }

    rep(k,n) rep(i,n) rep(j,n) G.at(i).at(j) |= G.at(i).at(k) & G.at(k).at(j);

    double ans = 0;
    rep(i,n) {
        int cnt = 1;
        rep(j,n) if (i != j && G.at(j).at(i)) ++cnt;
        ans += 1./cnt;
    }
    printf("%.10f\n", ans);

    return 0;
}