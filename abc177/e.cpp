#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int A = 1e6 + 5;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> c(A);
    rep(i,n) {
        cin >> a.at(i);
        c.at(a.at(i))++;
    }

    bool pairwise = true;
    for (int i = 2; i < A; ++i) {
        int count = 0;
        for (int j = i; j < A; j += i) {
            count += c.at(j);
        }
        if (count > 1) pairwise = false;
    }
    if (pairwise) {
        cout << "pairwise coprime" << endl;
        return 0;
    }
    
    int g = 0;
    rep(i,n) g = gcd(g, a.at(i));
    if (g == 1) {
        cout << "setwise coprime" << endl;
        return 0;
    }
    
    cout << "not coprime" << endl;

    return 0;
}