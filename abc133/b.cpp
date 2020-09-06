#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

bool isSquare(int n) {
    int r = floor(sqrt((long double) n));
    return (r * r) == n;
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<vector<int>> x(n, vector<int>(d));
    rep(i, n) {
        rep(j, d) cin >> x.at(i).at(j);
    }

    int count = 0;
    rep(i, n-1) {
        for(int j = i+1; j < n; j++) {
            int dis = 0;
            rep(k, d) {
                dis += (x.at(i).at(k) - x.at(j).at(k)) * (x.at(i).at(k) - x.at(j).at(k));
            }
            if(isSquare(dis)) count++;
        }
    }
    cout << count << endl;

    return 0;
}