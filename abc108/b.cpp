#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<P> p(4);

int main() {
    rep(i, 2) cin >> p.at(i).first >> p.at(i).second;

    P d = make_pair(p.at(1).first - p.at(0).first, p.at(1).second - p.at(0).second);
    
    for(int i = 2; i < 4; i++) {
        p.at(i).first = p.at(i-1).first - d.second;
        p.at(i).second = p.at(i-1).second + d.first;
        d.first = p.at(i).first - p.at(i-1).first;
        d.second = p.at(i).second - p.at(i-1).second;
    }

    printf("%d %d %d %d\n", p.at(2).first, p.at(2).second, p.at(3).first, p.at(3).second);

    return 0;
}