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
    int n, m;
    cin >> n >> m;
    vector<bool> stp(n);
    map<string,int> mp;
    rep(i,n) {
        string s;
        cin >> s;
        mp[s] = i;
    }
    rep(i,m) {
        string s;
        cin >> s;
        stp[mp.at(s)] = true;
    }
    rep(i,n) {
        cout << (stp[i] ? "Yes" : "No") << endl;
    }
    return 0;
}

