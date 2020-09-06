#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

void print(vector<int> &vt) {
    rep(i, vt.size()-1) cout << vt.at(i) << ' ';
    cout << vt.at(vt.size()-1) << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);
    rep(ki, k) {
        vector<int> b(n+1);
        rep(i,n) {
            int l = max(0, i-a.at(i));
            int r = min(i+a.at(i)+1, n);
            b.at(l)++; b.at(r)--;
        }
        print(b);
        rep(i,n) b.at(i+1) += b.at(i);
        b.pop_back();
        if(a == b) break;
        a = b;
    }
    print(a);

    return 0;
}