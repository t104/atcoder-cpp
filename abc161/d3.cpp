#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const int N = 12;
ll dp[10][N];
using P = pair<int,int>;
using T = tuple<int,int,ll>;

void printdp(){
        rep(i,10){
        rep(j,N){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
}

T search(int k){
    ll sum = 0;
    rep(i,N){
        rep(j,10){
            sum += dp[j][i];
            if(k <= sum){
                return make_tuple(i,j,sum);
            }
        }
    }
    return make_tuple(-1,-1,0);
}

void printT(T tup){
    cout << get<0>(tup) << ' ' << get<1>(tup) << ' ' << get<2>(tup) << endl; 
}

int main() {
    int k;
    cin >> k;
    for(int i = 1; i < 10; i++) dp[i][0] = 1;
    for(int i = 1; i < N; i++){
        rep(j,10){
            if(j-1 >= 0) dp[j-1][i] += dp[j][i-1];
            dp[j][i] += dp[j][i-1];
            if(j+1 <= 9) dp[j+1][i] += dp[j][i-1];
        }
    }
    // printdp();
    T target = search(k);
    printT(target);
    int count = get<2>(target) - dp[get<1>(target)][get<0>(target)];
    vector<char[N]> s;
    
    return 0;
}