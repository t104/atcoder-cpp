#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

const int max_ans = 3500;

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= max_ans; ++i) {
        for (int j = 1; j <= max_ans; ++j) {
            ll rhs = (ll) N * i * j;
            ll lhs = (ll) 4*i*j - (ll) N*i - (ll) N*j;
            if (0 < lhs && rhs%lhs == 0) {
                printf("%d %d %lld\n", i, j, rhs/lhs);
                return 0;
            }
        }
    }
    return 0;
}