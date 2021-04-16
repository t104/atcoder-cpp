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

const int MX = 200005;
vector<int> now(MX), nx(MX);

int main() {
    int n, k;
    cin >> n >> k;
    rep(i,n) cin >> now.at(i+1);
    rep(i,k) {
        bool end = true;
        for (int j = 1; j <= n; ++j) {
            if (now.at(j) < n) end = false;
        }
        if (end) break;

        rep(j,n+1) nx.at(j) = 0;
        for (int j = 1; j <= n; ++j) {
            nx[max(1,j - now.at(j))]++;
            if (j + now.at(j) + 1 <= n) {
                nx.at(j+now.at(j)+1)--;
            }
        }
        rep(j,n) nx.at(j+1) += nx.at(j);
        rep(j,n+1) now.at(j) = nx.at(j);
    }

    for (int i = 1; i <= n; ++i) {
        cout << now[i] << ' ';
    }
    cout << endl;
    return 0;
}