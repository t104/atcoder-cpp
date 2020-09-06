#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    rep(i, n) cin >> h.at(i);
    vector<int> a(m), b(m);
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        a.at(i) = x - 1;
        b.at(i) = y - 1;
    }

    vector<queue<int>> next(n);
    rep(i, m) {
        next.at(a.at(i)).push(b.at(i));
        next.at(b.at(i)).push(a.at(i));
    }

    int count = 0;
    rep(i, n) {
        bool good = true;
        while(!next.at(i).empty()) {
            int j = next.at(i).front(); next.at(i).pop();
            if(h.at(i) <= h.at(j)) {
                good = false;
                break;
            }
        }
        if(good) count++;
    }

    cout << count << endl;
    return 0;
}