#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<P> ac(n);
    rep(i,m) {
        int p;
        string s;
        cin >> p >> s;
        p--;
        if (ac.at(p).first == 0) {
            if (s == "WA") ac.at(p).second++;
            if (s == "AC") ac.at(p).first = 1;
        }
    }
    int nac = 0, np = 0;
    rep(i,n) {
        if (ac.at(i).first == 1) {
            nac++;
            np += ac.at(i).second;
        }
    }
    cout << nac << ' ' << np << endl;
    return 0;
}