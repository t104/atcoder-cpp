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

using mint = modint1000000007;

int main() {
    vector<mint> cnt(8);
    string s;
    cin >> s;
    map<char, int> mp;
    const string chokudai = "chokudai";
    rep(i,8) {
        mp[chokudai[i]] = i;
    }
    for (auto &c : s) {
        if (mp.count(c) == 0) continue;
        int i = mp.at(c);
        if (i == 0) cnt[i]++;
        else cnt[i] += cnt[i-1];
    }
    cout << cnt[7].val() << endl;
    return 0;
}