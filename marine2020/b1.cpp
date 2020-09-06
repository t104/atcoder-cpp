#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    ll a, v, b, w, t;
    cin >> a >> v >> b >> w >> t;

    ll d = abs(a-b);

    if((v-w)*t >= d) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;


    return 0;
}