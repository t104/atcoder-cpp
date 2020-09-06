#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    deque<int> b;
    if (n%2 == 0) {
        rep(i,n) {
            if (i%2 == 0) b.push_back(a.at(i));
            else b.push_front(a.at(i));
        }
    }
    else {
        rep(i,n) {
            if (i%2 == 0) b.push_front(a.at(i));
            else b.push_back(a.at(i));
        }
    }
    while (!b.empty()) {
        cout << b.front();
        b.pop_front();
        if (!b.empty()) cout << ' ';
    }
    cout << endl;

    return 0;
}