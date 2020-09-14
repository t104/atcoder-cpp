#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a.at(i);
    rep(i,n) cin >> b.at(i);

    map<int,int> mpa, mpb;
    for (int bi : b) mpb[bi]++;
    for (int ai : a) mpa[ai]++;
    int maxa = 0, A = 0;
    for (auto m : mpa) {
        if (maxa < m.second) {
            A = m.first;
            maxa = m.second;
        }
    }
    if (n/2 < b.at(A)) {
        cout << "NO" << endl;
        return 0;
    }
    

    return 0;
}