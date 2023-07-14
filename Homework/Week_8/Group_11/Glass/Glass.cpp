#include <bits/stdc++.h>
using namespace std;

int n, k, c[20][20], dp[1<<20], res = 1e6;

int getbit(int msk,int i) { return (msk>>i)&1; }

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];
    if (k == n) res = 0;
    for (int s = (1<<n) - 2; s > 0; s--) {
        dp[s] = 1e6;
        for (int i = 0; i < n; i++)
            if (getbit(s,i)==0)
                for (int j = 0; j < n; j++)
                    if (getbit(s,j)) 
                        dp[s] = min(dp[s], dp[s|(1<<i)] + c[i][j]);
        if (__builtin_popcount(s) <= k)
            res = min(res, dp[s]);
    }
    cout << res;
    return 0;
}