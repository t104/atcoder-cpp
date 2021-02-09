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
using P = pair<int,int>;

bool isAlphabet(char c) {
    return 'a' <= c && c <= 'z';
}

int main() {
    string s;
    cin >> s;
    ll x;
    cin >> x;

    while (true) {
        ll y = 0;
        for (auto c : s) {
            if (isAlphabet(c)) {
                if (x == y+1) {
                    cout << c << endl;
                    return 0;
                }
                ++y;
            }
            else {
                ll d = c - '0';
                if (x <= (d+1) * y) {
                    if (x%y) x %= y;
                    else x = y;
                    break;
                }
                y += d * y;
            }
        }
    }
    return 0;
}