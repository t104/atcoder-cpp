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

vector<P> a;
vector<int> ans;

void dfs(int v) {
    bool done = false;
    if (a[v].first == -1) {
        ans.push_back(v);
        done = true;
    } else {
        dfs(a[v].first);
    }
    if (a[v].second != -1) {
        dfs(a[v].second);
    }
    if (!done) {
        ans.push_back(v);
    }
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    a.assign(n+1, make_pair(-1, -1));
    rep(i,n) {
        if (s[i] == 'L') {
            a[i].first = i+1;
        }
        if (s[i] == 'R') {
            a[i].second = i+1;
        }
    }
    dfs(0);
    for (auto &i : ans) cout << i << ' ';
    cout << endl;
    return 0;
}

