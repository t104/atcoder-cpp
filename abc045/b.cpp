#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    vector<string> s(3);
    rep(i, 3) cin >> s.at(i);
    vector<int> cards(3);
    int turn = 0;
    while (true) {
        if (cards.at(turn) == s.at(turn).size()) {
            char ans = 'A' + turn;
            cout << ans << endl;
            break;
        }
        int next = s.at(turn).at(cards.at(turn)) - 'a';
        cards.at(turn)++;
        turn = next;
    }
    return 0;
}