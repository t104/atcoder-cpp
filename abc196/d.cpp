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

int h, w, a, b;
int ans;


void dfs(int i, int bit, int ai) {
    if (i == h*w) {
        if (ai == 0) ans++;
        return;
    }
    if (0 < ai && (~bit>>i)&1) {
        if (i%w < w-1 && (~bit>>(i+1))&1)
            dfs(i+2, bit | (1<<i+1), ai-1);
        if (i/w < h-1 && (~bit>>(i+w))&1)
            dfs(i+1, bit | (1<<(i+w)), ai-1);
    }
    dfs(i+1,bit,ai);
}

int main() {
    cin >> h >> w >> a >> b;
    ans = 0;
    dfs(0,0,a);
    cout << ans << endl;
    return 0;
}