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

bool win(char c, char d) {
    if (c == 'G') {
        return d == 'C';
    }
    if (c == 'C') {
        return d == 'P';
    }
    return d == 'G';
}

int main() {
    int n, m;
    cin >> n >> m;
    int N = 2*n;
    vector<string> s(N);
    rep(i,N) cin >> s[i];
    vector<P> order(N);
    rep(i,N) order[i].second = i;
    rep(i,m) {
        rep(j,n) {
            int a = order[2*j].second, b = order[2*j+1].second;
            if (win(s[a][i], s[b][i])) {
                order[2*j].first--;
            } else if (win(s[b][i], s[a][i])) {
                order[2*j+1].first--;
            }
        }
        sort(order.begin(), order.end());
    }
    rep(i,N) {
        cout << order[i].second + 1 << endl;
    }
    return 0;
}

