#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b < c || d < a) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}