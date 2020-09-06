#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int n, l;

bool comp (string x, string y) {
    return x+y<y+x;
}

int main() {
    cin >> n >> l;
    vector<string> s(n);
    rep(i,n) cin >> s.at(i);

    sort(s.begin(), s.end(), comp);
    string ans = "";
    ans.reserve(n*l);
    rep(i,n) ans += s.at(i);
    cout << ans << endl;
    
    return 0;
}