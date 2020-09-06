#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,string>;

int main() {
    int n;
    cin >> n;
    map<string, int> mp;
    int maxi = 0;
    rep(i,n) {
        string s;
        cin >> s;
        if(mp.count(s)) {
            mp.at(s)++;
        }
        else {
            mp[s] = 1;
        }
        maxi = max(maxi, mp.at(s));
    }
    
    for(auto a : mp) {
        if(a.second == maxi) cout << a.first << endl;
    }
    
    return 0;
}