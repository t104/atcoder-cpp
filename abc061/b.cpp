#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> roads(n, vector<int>());
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        roads.at(a).push_back(b);
        roads.at(b).push_back(a);
    }
    rep(i, n) cout << roads.at(i).size() << endl;
    return 0;
}