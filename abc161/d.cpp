#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

const int max_k = 1e5 + 5;

int main() {
    int k;
    cin >> k;
    deque<ll> q;
    for (int i = 1; i <= 9; ++i) {
        if (k == 0) break;
        k--;
        q.push_back(i);
    }
    while (k != 0) {
        ll x = q.front(); q.pop_front();
        ll qi = 10*x + x%10;
        if (0 < k && x%10 != 0) {
            q.push_back(qi-1);
            k--;
        }
        if (0 < k) {
            q.push_back(qi);
            k--;    
        }
        if (0 < k && x%10 != 9) {
            q.push_back(qi+1);
            k--;
        }
    }
    cout << q.back() << endl;
    return 0;
}