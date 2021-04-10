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
    string s;
    cin >> n >> s;
    vector<int> a(n+1);
    rep(i,n+1) cin >> a[i];
    vector<int> b(n+1);
    int mi = INF;
    rep(i,n) {
        chmin(mi, abs(a[i+1] - a[i]));
    }

    rep(i,n) {
        if (s[i] == '<') b[i+1] = b[i] + 1;
        else b[i+1] = b[i] - 1;
    }

    int bmi= *min_element(b.begin(), b.end());
    rep(i,n+1) b[i] -= bmi;

    rep(i,n+1) {
        if (0 < b[i]) chmin(mi, a[i]/b[i]);
    }

    cout << mi << endl;
    rep(i,mi-1) {
        rep(j,n+1) {
            cout << b[j];
            if (j < n) cout << ' ';
        }
        cout << endl;
    }
    
    rep(i,n+1) {
        a[i] -= b[i]*(mi-1);
    }
    rep(i,n+1) {
        cout << a[i];
        if (i < n) {
            cout << ' ';
            if (s[i] == '<') assert(a[i] < a[i+1]);
            else assert(a[i] > a[i+1]);
        }
    }
    cout << endl;

    return 0;
}