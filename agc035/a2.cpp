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

int n;
map<int,int> a;

bool ok() {
    if (a.count(0) && a.at(0) == n) return true;
    if (n%3 != 0) return false;
    if (a.size() == 2 && a.count(0) && a.at(0) == n/3) return true;
    if (a.size() == 3) {
        int prod = 0;
        for (auto p : a) {
            if (p.second != n/3) return false;
            prod ^= p.first;
        }
        return prod == 0;
    }
    return false;
}

int main() {
    cin >> n;
    rep(i,n) {
        int ai;
        cin >> ai;
        a[ai]++;
    }
    if (ok()) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}