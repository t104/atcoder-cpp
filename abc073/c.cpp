#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    set<int> a;
    rep(i,n) {
        int ai;
        cin >> ai;
        if (a.count(ai)) a.erase(ai);
        else a.insert(ai);
    }
    cout << a.size() << endl;
    return 0;
}