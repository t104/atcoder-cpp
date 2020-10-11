#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }
using ll = long long;
using P = pair<int,int>;

const int max_n = 1e9 + 5;
vector<int> cand;
vector<int> trip = {3,5,7};
queue<int> q;

int main() {
    int n;
    cin >> n;
    for (auto t : trip) {
        q.push(t);
        cand.push_back(t);
    }
    while (q.front() < max_n/10) {
        int x = q.front();
        q.pop();
        for (auto t : trip) {
            int y = x*10 + t;
            cand.push_back(y);
            q.push(y);
        }
    }
    int ans = 0;
    for (auto c : cand) {
        if (n < c) break;
        map<int,int> mp;
        while (0 < c) {
            mp[c%10]++;
            c /= 10;
            if (mp.count(3) && mp.count(5) && mp.count(7)) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}