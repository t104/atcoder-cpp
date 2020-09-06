#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main()
{
    ll i = 2011;
    for (ll div = 1; i / (div * 10) > 0; div *= 10)
    {
        if (abs(i / (div * 10) % 10 - (i / div) % 10) > 1)
        {
            cout << "No " << div << endl;
            break;
        }
    }
}