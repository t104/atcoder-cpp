#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;
const int mod = 1000000000;
const int MX = 25;

template<typename T>
struct BIT{
    private:
        vector<T> bit;
        const int n;
    public:
        BIT(int _n) : bit(_n + 1, 0), n(_n) {}

        T sum(int i) {
            T s(0);
            for (int idx = i; 0 < idx; idx -= (idx & -idx)) {
                s += bit[idx];
            }
            return s;
        }

        T sum(int l, int r) {
            return sum(r-1) - sum(l-1);
        }

        void add(int i, T x) {
            for (int idx = i; idx < n; idx += (idx & -idx)) {
                bit[idx] += x;
            }
        }
};

int main() {
    int k;
    cin >> k;
    vector<vector<int>> a(k);
    vector<int> n(k);
    rep(i,k) {
        cin >> n.at(i);
        a.at(i) = vector<int>(n.at(i));
        rep(j,n.at(i)) {
            cin >> a.at(i).at(j);
        }
    }
    int q;
    cin >> q;
    vector<int> x;
    rep(i,q) {
        int b;
        cin >> b;
        --b;
        for (auto ai : a.at(b)) {
            x.push_back(ai);
        }
    }

    ll ans = 0;
    int xn = x.size();
    BIT<int> bt(xn);
    rep(i,xn) {
        ans += i - bt.sum(x.at(i));
        ans %= mod;
        bt.add(x.at(i), 1);
    }
    cout << ans << endl;
    return 0;
}