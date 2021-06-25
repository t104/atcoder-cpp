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

vector<vector<ll>> dp(5010, vector<ll>(5010));

struct Job {
    int d,c;
    ll s;
    Job(int d = 0, int c = 0, ll s = 0): d(d), c(c), s(s) {}
    bool operator<(Job &rhs) const {
        return d < rhs.d;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Job> jobList(n);
    rep(i,n) cin >> jobList[i].d >> jobList[i].c >> jobList[i].s;
    sort(jobList.begin(), jobList.end());
    rep(i,n) {
        rep(j,5010) {
            chmax(dp[i+1][j], dp[i][j]);
            if (j + jobList[i].c <= jobList[i].d) {
                chmax(dp[i+1][j+jobList[i].c], dp[i][j] + jobList[i].s);
            }
        }
    }
    cout << *max_element(dp[n].begin(), dp[n].end()) << endl;
    return 0;
}