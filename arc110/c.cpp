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

void dame() {
    cout << -1 << endl;
    exit(0);
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    vector<int> sp(n);
    vector<int> q(n);
    rep(i,n) {
        p[i]--;
        q[p[i]] = i;
    }

    vector<int> ans;
    rep(i,n) {
        int d = q[i] - i;
        for (int j = q[i]; i < j; --j) {
            if (sp[j-1]) dame();
            ans.push_back(j-1);
            sp[j-1]++;
            swap(q[i], q[p[j-1]]);
            swap(p[j],p[j-1]);
        }
    }

    rep(i,n-1) {
        if (sp[i] != 1) dame();
    }

    for (auto ai: ans) {
        cout << ai+1 << endl;
    }
    return 0;
}