#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int max_n = 100005;

map<P, int> mp;
vector<vector<int>> G(max_n);

void dfs(int now, int p, int pc) {
    int color = 1;
    if (color == pc) ++color;
    for (auto e : G.at(now)) {
        if (e == p) continue;
        P edge = {min(now, e), max(now, e)};
        mp[edge] = color;
        dfs(e, now, color);
        ++color;
        if (color == pc) ++color;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n-1), b(n-1);
    rep(i,n-1) {
        cin >> a.at(i) >> b.at(i);
        a.at(i)--; b.at(i)--;
    }
    
    rep(i,n-1) {
        G.at(a.at(i)).push_back(b.at(i));
        G.at(b.at(i)).push_back(a.at(i));
    }

    dfs(0, -1, 0);

    vector<int> ans(n-1);
    int ansn = 0;
    rep(i,n-1) {
        ans.at(i) = mp.at({min(a.at(i), b.at(i)), max(a.at(i), b.at(i))});
        chmax(ansn, ans.at(i));
    }

    cout << ansn << endl;
    rep(i,n-1) cout << ans.at(i) << endl;
    return 0;
}