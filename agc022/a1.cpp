#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);
//const ll mod = 998244353;

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}


int main(void)
{
    string s, ans;
    cin >> s;
    ans = s;
    if(s.size() < 26){
        map<char,ll> mp;
        rep(i,s.size()) mp[s[i]]++;
        for(char c='a'; c<='z'; c++){
            if(!mp[c]){
                ans += c;
                break;
            }
        }
    }else{
        if(!next_permutation(all(ans))) ans = "-1";
        else{
            rep(i,26){
                if(s[i] != ans[i]){
                    ans.resize(i+1);
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
