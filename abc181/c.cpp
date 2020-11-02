#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i,n) cin >> x.at(i) >> y.at(i);
    rep(i,n) {
        for (int j = i+1; j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                int xij = x.at(j) - x.at(i);
                int yij = y.at(j) - y.at(i);
                int xjk = x.at(k) - x.at(j);
                int yjk = y.at(k) - y.at(j);
                if (yij * xjk == xij * yjk) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}