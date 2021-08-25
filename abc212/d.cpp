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

using pq = priority_queue<ll, vector<ll>, greater<ll>>;

struct myque {
    vector<ll> dif;
    vector<pq> ques;
    void push(ll x) {
        if (dif.size() && dif.back() == 0) {
            ques.back().push(x);
        } else {
            pq q;
            q.push(x);
            ques.push_back(q);
            dif.push_back(0);
        }
    }

    void add(ll x) {
        if (dif.size() == 0) return;
        if (ques.back().size() < 100) {
            pq tmp;
            while (ques.back().size()) {
                ll i = ques.back().top(); ques.back().pop();
                tmp.push(i + x);
            }
            swap(ques.back(), tmp);
            int n = dif.size();
            if (2 <= n) {
                dif[n-2] += x;
            }
            return;
        }
        dif.back() += x;
    }

    ll pop() {
        ll res = LINF;
        ll d = 0;
        int n = dif.size();
        int idx = 0;
        for (int i = n-1; 0 <= i; --i) {
            d += dif[i];
            if (res <= d) break;
            if (ques[i].empty()) continue;
            if (chmin(res, ques[i].top() + d)) idx = i;
        }
        ques[idx].pop();
        return res;
    }
};

myque mq;

void solve() {
    int qi;
    ll xi;
    cin >> qi;
    if (qi == 3) {
        cout << mq.pop() << endl;
        return;
    }
    cin >> xi;
    if (qi == 1) mq.push(xi);
    else mq.add(xi);
}

int main() {
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}