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

int n, m, k;
vector<P> ans;

clock_t start;
const clock_t LIMIT = 1.9 * CLOCKS_PER_SEC;

struct powers {
    vector<int> a;
    int cnt;
    vector<P> procedure;
    mt19937 mt;
    bool initial = false;
    
    powers(vector<int> a): a(a) {
        cnt = m;
        random_device rd;
        mt = mt19937(rd());
    }

    powers() {
        initial = true;
    }
    
    void magik (int p, int q) {
        a[p] += a[q];
        a[p] %= k;
        procedure.emplace_back(p, q);
        cnt--;
    }

    void run() {
        while(cnt) {
            int i = mt() % n;
            if (a[i] == 0) continue;
            int zero_p = -1, zero_q = INF;
            int p = 0, mi = INF;
            
            rep(j,n) {
                if (a[j] == 0) continue;
                if ((k - a[i]) % a[j] == 0) {
                    if (chmin(zero_q, (k - a[i]) / a[j])) zero_p = j;
                }
                if (chmin(mi, (a[i] + a[j]) % k)) p = j;
            }

            if (0 <= zero_p && zero_q <= cnt) {
                rep(qi, zero_q) magik(i, zero_p);
                continue;
            }
            magik(i, p);
        }
    }

    void print_procedure() {
        for (auto p : procedure) cout << p.first << ' ' << p.second << endl;
    }

    int zeros() {
        if (initial) return INF;
        int res = 0;
        rep(i,n) res += a[i] == 0;
        return res;
    }
};

int main() {
    cin >> n >> m >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    powers ans;
    while (true) {
        if (LIMIT < clock() - start) {
            ans.print_procedure();
            return 0;
        }
        powers pw(a);
        pw.run();
        if (pw.zeros() < ans.zeros()) swap(ans, pw);
    }
    return 0;
}