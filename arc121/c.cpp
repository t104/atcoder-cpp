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

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) {
        cin >> p[i];
        p[i]--;
    }
    vector<int> ans;
    int cnt = 0;

    auto sw = [&](int x, int y) {
        ans.push_back(x);
        swap(p[x], p[y]);
        cnt++;
    };
    
    int r = n-1;
    while (0 <= r) {
        if (p[r] == r) {
            r--;
            continue;
        }
        rep(i,n) {
            if (p[i] == r) {
                if (cnt%2 != i%2) {
                    sw(cnt%2, cnt%2+1);
                    break;
                }
                while (i < r) {
                    sw(i, i+1);
                    ++i;
                }
                r--;
                break;
            }
        }
    }

    cout << cnt << endl;
    for (auto ai: ans) {
        cout << ai+1 << ' ';
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    rep(i,t) solve();
    return 0;
}