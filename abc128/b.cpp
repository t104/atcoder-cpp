#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using tup = tuple<string, int, int>;

int main() {
    int n;
    cin >> n;
    vector<tup> rest(n);
    rep(i,n) {
        string s;
        int m;
        cin >> s >> m;
        rest.at(i) = make_tuple(s, m, i);
    }
    sort(rest.begin(), rest.end(), [](tup x, tup y) {
        if (get<0>(x) == get<0>(y)) {
            return get<1>(y) < get<1>(x);
        }
        return get<0>(x) < get<0>(y);
    });
    rep(i,n) cout << get<2>(rest.at(i)) + 1 << endl;
    return 0;
}