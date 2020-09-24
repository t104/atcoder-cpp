#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
    ll n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    ll g = gcd(n,m);
    bool ok = true;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s.at(i) != t.at(j)) ok = false;
        i += n/g;
        j += m/g;
    }
    
    if (ok) cout << n / g * m << endl;
    else cout << -1 << endl;
    return 0;
}