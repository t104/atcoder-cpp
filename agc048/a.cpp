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

const string x = "atcoder";
const int m = x.size();

int solve() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = INF;
    int cnt = 0;
    rep(i,min(n,m)) {
        for (int j = i; j < n; ++j) {
            if (x[i] < s[j]) {
                chmin(ans, cnt+j-i);
                break;
            }
        }
        bool ok = x[i] <= s[i];
        if (!ok) {
            for (int j = i; j < n; ++j) {
                if (x[i] <= s[j]) {
                    for (int k = j; i < k; --k) {
                        swap(s[k-1], s[k]);
                        cnt++;
                    }
                    ok = true;
                    break;
                }
            }
        }
        if (!ok) {
            if (ans == INF) return -1;
            return ans;
        }
    }
    if (ans == INF) return -1;
    if (m < n) chmin(ans, cnt);
    return ans;
}

int main() {
    int t;
    cin >> t;
    vector<int> sol(t), ans(t);
    rep(i,t) cout << solve() << endl;
    return 0;
}