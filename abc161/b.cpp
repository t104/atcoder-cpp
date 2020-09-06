#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    int sum = 0;
    rep(i,n) sum += p[i];
    int count = 0;
    rep(i,n) if(p[i]*4*m >= sum) count++;
    if(count >= m) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}