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

double p;

double f(double x) {
    return x + p * pow(2, -x/1.5);
}

int main() {
    cout << std::fixed << std::setprecision(15);
    cin >> p;
    double x = 1.5 * (1 - log2(3 / (p * log(2))));
    cout << x << endl;
    if (0 < x) {
        cout << f(x) << endl;
        return 0;
    }
    cout << f(0.0) << endl;
    return 0;
}