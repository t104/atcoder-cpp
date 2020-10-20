#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

const int max_n = 100005;
const int INF = 1001001001;

int main() {
    int n;
    cin >> n;
    int res = n;
    for (int i = 0; i <= n; ++i) {
        int cc = 0;
        int t = i;
        while (0 < t) cc += t%6, t/= 6;
        t = n - i;
        while (0 < t) cc += t%9, t/=9;
        if (cc < res) res = cc;
    }
    cout << res << endl;
    return 0;
}