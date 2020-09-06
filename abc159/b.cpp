#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

bool IsReversible(string s) {
    string r = s;
    reverse(r.begin(), r.end());
    return s == r;
}

int main() {
    string S;
    cin >> S;
    int N = S.size();
    string S_half1 = S.substr(0, (N-1)/2);
    string S_half2 = S.substr((N+1)/2, N-1);
    if(IsReversible(S) && IsReversible(S_half1) && IsReversible(S_half2))
        cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}