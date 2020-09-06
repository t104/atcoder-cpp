#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int memo[205][205];

int gcd(int a, int b) { return b?gcd(b,a%b):a;}
int gcd_memo(int a, int b){
    if(memo[a][b] != 0) return memo[a][b];
    else{
        int g = gcd(a,b);
        memo[a][b] = g;
        return g;
    }
}

int main() {
    int k;
    cin >> k;
    int sum = 0;
    for(int i = 1; i <= k; i++)
        for(int j = 1; j <= k; j++)
            for(int l = 1; l <= k; l++)
                sum += gcd_memo(gcd_memo(i,j), gcd_memo(j,l));

    cout << sum << endl;
    return 0;
}