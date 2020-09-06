#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const int INF = 99999999;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> vW(N+1,0), vE(N+1,0);
    for(int i=0; i<N; i++){
        vW[i+1] += vW[i];
        if(S[i] == 'W') vW[i+1]++;
        vE[i+1] += vE[i];
        if(S[i] == 'E') vE[i+1]++;
    }

    rep(i,N){
        cout << vW[i] << ' ' << vE[i] << endl;
    }

    int ans = INF;
    for(int i=0; i<N; i++){
        int now = vW[i] + (vE[N]-vE[i+1]);
        if(ans > now) ans = now;
    }
    // cout << ans << endl;
    return 0;
}