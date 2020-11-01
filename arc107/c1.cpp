#include<atcoder/all>
using namespace atcoder;

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

using MLL = static_modint<998244353>;
MLL F[51];

int main() {
	F[0] = 1; for (int i = 1; i <= 50; i++) F[i] = F[i - 1] * i;

	int N, K; cin >> N >> K;
	int A[50][50]; rep(y, N) rep(x, N) cin >> A[y][x];
	dsu X(N), Y(N);
	rep(x1, N) rep(x2, x1) {
		bool ok = true;
		rep(y, N) if (A[y][x1] + A[y][x2] > K) ok = false;
		if (ok) X.merge(x1, x2);
	}
	rep(x1, N) rep(x2, x1) {
		bool ok = true;
		rep(y, N) if (A[x1][y] + A[x2][y] > K) ok = false;
		if (ok) Y.merge(x1, x2);
	}

	MLL ans = 1;

	auto XV = X.groups();
	for (auto x : XV) ans *= F[x.size()];
	auto YV = Y.groups();
	for (auto x : YV) ans *= F[x.size()];

	cout << ans.val() << endl;

	return 0;
}
