#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    rep(i, n) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    vector<P> cards(m);
    rep(i,m) {
        cin >> cards.at(i).second >> cards.at(i).first;
    }
    sort(cards.begin(), cards.end());
    reverse(cards.begin(), cards.end());

    ll ans = 0;
    int j = 0, k = 0;
    rep(i, n) {
        if(k == m || a.at(j) >= cards.at(k).first) {
            ans += a.at(j);
            j++;
            continue;
        }
        int c = min(n-i, cards.at(k).second);
        ans += (ll)cards.at(k).first * c;
        k++;
        i += c-1;
    }
    cout << ans << endl;

    return 0;
}