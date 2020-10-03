#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    vector<int> order(n);
    stack<int> ans;
    rep(i,n) order.at(i) = i + 1;
    rep(i,n) {
        bool found = false;
        for (int j = n-1; 0 <= j; --j) {
            if (order.at(j) == a.at(j)) {
                found = true;
                ans.push(a.at(j));
                order.at(j) = 0;
                for (int k = j+1; k < n; k++) order.at(k)--;
                break;
            }
        }
        if (!found) {
            cout << -1 << endl;
            return 0;
        }
    }

    while (!ans.empty()) {
        cout << ans.top() << endl;
        ans.pop();
    }
    return 0;
}