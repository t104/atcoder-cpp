#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using tup = tuple<int,int,int>;

struct city {
    int no, prefecture, year;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<city> c(m);
    rep(i,m) {
        c.at(i).no = i;
        cin >> c.at(i).prefecture >> c.at(i).year;
    }
    sort(c.begin(), c.end(), [](city x, city y) {
        if (x.prefecture == y.prefecture) return x.year < y.year;
        return x.prefecture < y.prefecture;
    });
    vector<string> ans(m);
    int p = 0, id = 0;
    rep(i,m) {
        if (p == c.at(i).prefecture) id++;
        else id = 1;
        p = c.at(i).prefecture;
        ostringstream pss, idss;
        pss << setfill('0') << setw(6) << p;
        idss << setfill('0') << setw(6) << id;
        ans.at(c.at(i).no) = pss.str() + idss.str();
    }
    rep(i,m) cout << ans.at(i) << endl;
    return 0;
}