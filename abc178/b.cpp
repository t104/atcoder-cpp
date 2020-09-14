#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<ll> ans;
    ans.push_back(a*c);
    ans.push_back(a*d);
    ans.push_back(b*c);
    ans.push_back(b*d);
    cout << *max_element(ans.begin(), ans.end()) << endl;
    return 0;
}