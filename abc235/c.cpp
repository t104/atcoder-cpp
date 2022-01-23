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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    map<int, vector<int>> mp;
    rep(i,n) {
        mp[a[i]].push_back(i);
    }
    while (q--) {
        int x, k;
        cin >> x >> k;
        if (mp.count(x) && k <= mp.at(x).size()) {
            cout << mp.at(x).at(k-1) + 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}

