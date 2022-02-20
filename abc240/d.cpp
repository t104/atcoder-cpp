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

int main() {
    int n;
    cin >> n;
    int last = -1, cnt = 0, same = 0;
    vector<P> ans;
    rep(i,n) {
        int a;
        cin >> a;
        if (a != last) {
            ans.emplace_back(last, same);
            last = a;
            same = 1;
            cnt++;
        } else {
            cnt++;
            same++;
            if (same == last) {
                cnt -= same;
                last = ans.back().first;
                same = ans.back().second;
                ans.pop_back();
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

