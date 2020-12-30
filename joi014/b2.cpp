#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long
#define rep(i, n) for(int i = 0;i<(int)(n);i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int,int>;

bool chmax(int &a,int b) {
    if(a<b) {
        a=b;
        return true;
    }
    return false;
}

int n;
int dp[5000][5000];
int v[5000];

int rec(int l,int r) {
    if(l<0||r>=5000||l>=r) return 0;
    if(dp[l][r]) return dp[l][r];
    if(r-l==1) return dp[l][r]=v[l];
    int a,b;
    if(v[l+1]<v[r-1]) a = v[l]+rec(l+1,r-1);
    else a = v[l]+rec(l+2,r);
    if(v[l]<v[r-2]) b = v[r-1]+rec(l,r-2);
    else b = v[r-1]+rec(l+1,r-1);
    return dp[l][r]=max(a,b);
}

signed main() {
    cin >> n;
    rep(i, n) cin >> v[i],v[n+i]=v[i];
    int ma = 0;
    rep(i, n) chmax(ma,rec(i,i+n));
    // cout << ma << endl;
    rep(i,2*n) {
        rep(j,2*n) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    } 
    return 0;
}