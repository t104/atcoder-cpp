#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

const long double PI = acos(-1);

int main() {
    int a, b, x;
    cin >> a >> b >> x;
    long double ans;
    if (a*a*b <= 2*x) {
        ans = atan((long double) 2*(a*a*b-x)/(a*a*a));
    }
    else ans = PI/2 - atan((long double) 2*x/(a*b*b));
    cout << std::fixed << std::setprecision(15);
    cout << ans*180.0/PI << endl;
    return 0;
}