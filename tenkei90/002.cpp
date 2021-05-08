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

int n;
vector<string> ans;

void dfs(int i, int x, string s) {
    if (i == n) {
        if (x == 0) ans.push_back(s);
        return;
    }

    dfs(i+1, x+1, s+"(");
    
    if (0 < x) {
        dfs(i+1, x-1, s+")");
    }
}

int main() {
    cin >> n;
    dfs(0, 0, "");
    for (auto si: ans) cout << si << endl;
    return 0;
}