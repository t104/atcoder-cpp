#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n, -1);
    bool ok = true;
    rep(i,m) {
        int s, c;
        cin >> s >> c;
        if (a.at(s-1) == -1 ) {
            a.at(s-1) = c;
        }
        else ok = a.at(s-1) == c;
    }

    if (n!=1 && a.at(0) == 0) ok = false;
    if(!ok) {
        cout << -1 << endl;
        return 0;
    }
    if (n==1 && a.at(0) == -1) {
        cout << 0 << endl;
        return 0;
    }
    rep(i,n) {
        if(a.at(i) == -1) {
            a.at(i) = i == 0 ? 1:0;
        }
        cout << a.at(i);
    }
    cout << endl;
    return 0;
}