#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n;
    map<string, int> cards;
    rep(i,n) {
        string s;
        cin >> s;
        cards[s]++;
    }
    cin >> m;
    rep(i,m) {
        string t;
        cin >> t;
        if (!cards.count(t)) cards[t] = 0;
        cards.at(t)--;
    }

    int ans = 0;
    for (auto card : cards) {
        ans = max(ans, card.second);
    }
    if (ans < 0) ans = 0;
    cout << ans << endl;

    return 0;
}