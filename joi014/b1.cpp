#include <bits/stdc++.h>
using namespace std;
int64_t DP[4100][4100];
int64_t A[4100];
int64_t N;

int64_t calc(int l, int r, bool joisTurn)
{
  if (DP[l][r] != -1) // メモ化済み
    return DP[l][r];
  if (l == r)
  {
    if (joisTurn)
      return DP[l][r] = A[l];
    return DP[l][r] = 0;
  }
  if (joisTurn)
  {
    return DP[l][r] = max(A[l] + calc(l + 1, r, false), calc(l, r - 1, false) + A[r]);
  }
  if (A[l] > A[r])
    return DP[l][r] = calc(l + 1, r, true);
  else
    return DP[l][r] = calc(l, r - 1, true);
}

void init()
{
  for (int i = 0; i < 4100; i++)
    for (int j = 0; j < 4100; j++)
      DP[i][j] = -1;
}

int main()
{
  cin >> N;
  for (int i = 1; i <= N; i++)
  {
    cin >> A[i];
    A[i + N] = A[i];
  }
  init(); // DPテーブルを-1で初期化
  int64_t ans = 0;
  for (int i = 1; i <= N; i++)
  {
    ans = max(ans, calc(i, i + N - 1, true)); // s
  }
  cout << ans << endl;
}