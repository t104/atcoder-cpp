#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> r;
    vector<int> g;
    vector<int> b;
    rep(i,n){
        if(s.at(i) == 'R') r.push_back(i);
        else if(s.at(i) == 'G') g.push_back(i);
        else b.push_back(i);
    }
    ll sum =(ll) r.size() * g.size() * b.size();
    auto isB = [&](int k){
        return 0 <= k && k < n && s.at(k) == 'B';
    };
    for(int i : r)
        for(int j : g){
            int k1 = 2*i-j;
            int k2 = (i+j)%2 == 0 ? (i+j)/2 : -1;
            int k3 = 2*j-i;
            if(isB(k1)) sum--;
            if(0 <= k2 && k2 < n && s.at(k2) == 'B') sum--;
            if(0 <= k3 && k3 < n && s.at(k3) == 'B') sum--; 
        }
    
    cout << sum << endl;
    return 0;
}