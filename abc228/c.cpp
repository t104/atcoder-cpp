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
    int n, k;
    cin >> n >> k;
    vector<int> scores(n), sorted_scores(n);
    rep(i,n) {
        int a, b, c;
        cin >> a >> b >> c;
        scores[i] = 1200 - a - b - c;
        sorted_scores[i] = scores[i];
    }
    sort(sorted_scores.begin(), sorted_scores.end());
    for (auto &sc : scores) {
        int new_sc = sc - 300;
        int rank = lower_bound(sorted_scores.begin(), sorted_scores.end(), new_sc) - sorted_scores.begin();
        if (rank < k) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}

