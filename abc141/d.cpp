#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<int> a;
    rep(i, n) {
        int ai;
        cin >> ai;
        a.push(ai);
    }

    rep(i, m) {
        int j = a.top();
        a.pop();
        a.push(j/2);
    }
    ll sum = 0;
    while(!a.empty()) {
        sum += a.top();
        a.pop();
    }

    cout << sum << endl;
    return 0;
}