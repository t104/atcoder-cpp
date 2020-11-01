#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    dsu related(n);
    vector<set<int>> blocks(n), friends(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        related.merge(a,b);
        friends.at(a).insert(b);
        friends.at(b).insert(a);
    }
    rep(i,k) {
        int c, d;
        cin >> c >> d;
        --c; --d;
        blocks.at(c).insert(d);
        blocks.at(d).insert(c);
    }
    vector<int> ans(n, -1);
    for (auto g : related.groups()) {
        for (auto x : g) {
            ans.at(x) = g.size() - friends.at(x).size() - 1;
            for (auto b : blocks.at(x)) {
                if (related.same(x, b)) ans.at(x)--;
            }
        }
    }
    rep(i,n) cout << ans.at(i) << endl;
    return 0;
}