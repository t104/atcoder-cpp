#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    set<int> ans;
    for(int i = 0; i < k && a+i <= b; i++) {
        ans.insert(a+i);
        ans.insert(b-i);
    }
    for(int i : ans) {
        cout << i << endl;
    }
    return 0;
}