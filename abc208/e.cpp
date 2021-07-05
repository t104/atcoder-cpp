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

vector<vector<int>> fact;

ll n, k, ans;
int digit_count;
vector<int> n_split;

ll comb(int n, int r) {
    vector<vector<ll>> v(n+1, vector<ll>(n+1, 0));
    rep(i, v.size()) {
        v.at(i).at(0) = 1;
        v.at(i).at(i) = 1;
    }
    for (int j = 1; j < v.size(); ++j) {
        for (int k = 1; k < j; ++k) {
            v.at(j).at(k) = v.at(j-1).at(k-1) + v.at(j-1).at(k);
        }
    }
    return v[n][r];
}

ll count_all(vector<int> &f) {
    ll now = 1;
    int digits = f.size();
    vector<int> cnt(10);
    for (auto &fi : f) cnt[fi]++;
    for (auto &c : cnt) {
        now *= comb(digits, c);
        digits -= c;
    }
    return now;
}

bool small(vector<int> &f) {
    rep(i, digit_count) {
        if (f[i] < n_split[i]) return true;
        if (n_split[i] < f[i]) return false;
    }
    return true;
}

void dfs(int i, int s, ll p, vector<int> f) {
    if (i == digit_count) {
        ll x = 0;
        for (int j = i-1; 0 <= j; --j) {
            x *= 10;
            x += f[j];
        }
        if (x <= n) ans += count_all(f);
        else {
            do {
                if (small(f)) ans++;
            } while (next_permutation(f.begin(), f.end()));
        }
        return;
    }
    ans += count_all(f);
    for (int j = s; j < 10; ++j) {
        if (p * j <= k) {
            f.push_back(j);
            dfs(i+1, j, p*j, f);
        }
    }
}

void init() {
    ll m = n;
    ans = 0;
    digit_count = 0;
    while (m) {
        digit_count++;
        n_split.push_back(m%10);
        m /= 10;
    }
    reverse(n_split.begin(), n_split.end());
    dfs(0, 1, 1, {});
}

void print_fact() {
    for (auto &f: fact) {
        for (auto fi: f) {
            cout << fi << ' ';
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> k;
    init();
    cout << ans << endl;
    return 0;
}