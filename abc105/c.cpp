#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

const int max_k = 40;
vector<int> ans(max_k);

void dfs(ll n) {
    if (n == 0) return;
    ll x = 0;
    if (0 < n) {
        for (int i = 0; i < max_k; i+=2) {
            ll xi = 1LL<<i;
            x += xi;
            if (n <= x) {
                ans.at(i) = 1;
                dfs(n - xi);
                return;
            }
        }
    }
    if (n < 0) {
        for (int i = 1; i < max_k; i+=2) {
            ll xi = 1LL<<i;
            x -= xi;
            if (x <= n) {
                ans.at(i) = 1;
                dfs(n + xi);
                return;
            }
        }
    }
}

int main() {
    ll n;
    cin >> n;
    dfs(n);
    string s = "";
    bool write = false;
    if (n==0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = max_k-1; 0 <= i; --i) {
        if (ans.at(i) == 1) write = true;
        if (write) s.push_back('0' + ans.at(i));
    }
    cout << s << endl;
    return 0;
}