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
    int k;
    string s, t;
    cin >> k >> s >> t;
    s.pop_back();
    t.pop_back();
    vector<int> cards(10, k);
    vector<int> taka(10), ao(10);
    auto remove = [&](string str) {
        for (auto c: str) {
            cards[c-'0']--;
        }
    };
    remove(s);
    remove(t);
    for (auto c: s) taka[c-'0']++;
    for (auto c: t) ao[c-'0']++;

    ll win = 0, lose = 0;
    for (int i = 1; i < 10; ++i) {
        if (cards[i] == 0) continue;
        ll ci = cards[i];
        cards[i]--;
        for (int j = 1; j < 10; ++j) {
            ll cj = cards[j];
            if (cj == 0) continue;
            ll cnt = ci * cj;
            ll pt = 0, pa = 0;
            for (int l = 1; l < 10; ++l) {
                ll p = l;
                int x = taka[l];
                if (i == l) x++;
                rep(m,x) p *= 10;
                pt += p;
            }
            for (int l = 1; l < 10; ++l) {
                ll p = l;
                int x = ao[l];
                if (j == l) x++;
                rep(m,x) p *= 10;
                pa += p;
            }
            if (pa < pt) win += cnt;
            else lose += cnt;
        }
        cards[i]++;
    }

    cout << std::fixed << std::setprecision(15);
    ld ans = (ld) win/(win + lose);
    cout << ans << endl;

    return 0;
}