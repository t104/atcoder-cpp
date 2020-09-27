#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a.at(i);

    vector<int> first(h), last(h);
    rep(i, h) {
        first.at(i) = a.at(i).find('#');
        last.at(i) = a.at(i).rfind('#');
    }
    for (int i = 1; i < h; i++) {
        if (last.at(i-1) != first.at(i)) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    cout << "Possible" << endl;
    return 0;
}