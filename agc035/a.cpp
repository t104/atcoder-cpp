#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int n;
vector<int> a;

bool solve () {
    map<int,int> mp;
    rep(i,n) mp[a.at(i)]++;
    if (mp.size() == 1 && mp.count(0)) return true;
    else if (n%3 != 0) return false;
    else if (mp.size() == 2) {
        for (auto p : mp) {
            if (p.second%(n/3) != 0) return false;
        }
        return true;
    }

    vector<int> e;
    for (auto p : mp) {
        if (p.second != n/3) return false;
        e.push_back(p.first);
    }
    if (e.size() != 3) return false;
    if (((e.at(0) ^ e.at(1)) ^ e.at(2)) == 0) return true;
    else return false;
}

int main() {
    cin >> n;
    a.resize(n);
    rep(i,n) cin >> a.at(i);

    if (solve()) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
