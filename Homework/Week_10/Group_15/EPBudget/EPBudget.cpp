#include <bits/stdc++.h>

using namespace std;

int Process(vector<vector<int>> A, vector<int> Nodes)
{
  int n = A.size(), k = Nodes.size();
  for(int i = 0; i < n; ++i)
    for(int u = 0; u < n; ++u)
      for(int v = 0; v < n; ++v)
        A[u][v] = min(A[u][v], A[u][i] + A[i][v]);
  vector<vector<int>> f(1<<(k), vector<int>((k), INT_MAX));
  f[1][0] = 0;
  for(int mask = 1; mask < 1<<k; mask++)
    for(int u = 0; u < k; ++u)
      if (mask & (1<<u) && f[mask][u] != INT_MAX)
        for(int v = 0; v < k; ++v)
          if (!(mask & (1<<v)))
            f[mask | (1<<v)][v] = min(f[mask | (1<<v)][v], f[mask][u] + A[Nodes[u]][Nodes[v]]);
  int res = INT_MAX;
  for(int i = 0; i < k; ++i)
    res = min(res, f[(1<<k)-1][i]);
  return res;
}
int main()
{
  int n, k;
  cin >> n >> k;
  vector<vector<int>> A(n, vector<int>(n,0));
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      cin >> A[i][j];
  vector<int> Nodes(k+1);
  for(int i = 1; i <= k; ++i) {
    cin >> Nodes[i];
    Nodes[i]--;
  }
  cout << Process(A, Nodes);
	return 0;
}