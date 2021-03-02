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

bool check(vector<P> s) {
    int h = 0;
    for (P p: s) {
        int b = h + p.first;
        if (b < 0) return false;
        h += p.second;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<P> ls, rs;
    int total = 0;
    rep(i,n) {
        string s;
        cin >> s;
        int h = 0, b = 0;
        for (char c: s) {
            if (c == '(') ++h; else --h;
            chmin(b,h);
        }
        total += h;
        if (0 < h) ls.emplace_back(b, h);
        else rs.emplace_back(b-h, -h);
    }
    sort(ls.rbegin(), ls.rend());
    sort(rs.rbegin(), rs.rend());
    if (check(ls) && check(rs) && total == 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    
    return 0;
}