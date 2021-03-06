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

int main() {
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;

    vector<int> l(n);
    int cnt = 0;
    for (int li = 0; li < n;) {
        if (s[li] == 'o') {
            cnt++;
            l[li] = cnt;
            li += c+1;
        }
        else {
            li++;
        }
    }

    vector<int> r(n);
    cnt = k;
    for (int ri = n-1; 0 <= ri;) {
        if (s[ri] == 'o') {
            r[ri] = cnt;
            cnt--;
            ri -= c+1;
        }
        else {
            ri--;
        }
    }

    rep(i,n) {
        if (l[i] != 0 && l[i] == r[i]) {
            cout << i+1 << endl;
        }
    }

    return 0;
}