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

ll convert_from8(string s) {
    ll res = 0;
    for (char c: s) {
        res *= 8LL;
        int r = c - '0';
        res += r;
    }
    return res;
}

string convert(ll n) {
    string res = "";
    while (n) {
        int r = n % 9;
        n /= 9;
        char c = r == 8 ? '5' : '0' + r;
        res.push_back(c);
    }
    reverse(res.begin(), res.end());
    if (res.size() == 0) return "0";
    return res;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    rep(i,k) {
        ll x = convert_from8(s);
        s = convert(x);
    }
    cout << s << endl;

    return 0;
}