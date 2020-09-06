#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n;
    map<int, int> d;
    rep(i,n) {
        int di;
        cin >> di;
        if (!d.count(di)) d[di] = 1;
        else d.at(di)++;
    }
    cin >> m;
    rep(i,m) {
        int ti;
        cin >> ti;
        if (d.count(ti) && 0 < d.at(ti)) d.at(ti)--;
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    return 0;
}