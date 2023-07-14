#include <bits/stdc++.h>

using namespace std;

pair<long, long> dp[1<<20];
long n, x, w[20];

int main() {
    cin >> n >> x;
    for(int i = 0; i < n; i++)
        cin >> w[i];
    dp[0] = {0, x};
    for(int i = 1; i < 1<<n; i++)
        dp[i].first = n;
    for(int i = 1; i < 1<<n; i++) 
        for(int j = 0; j < n; j++) 
            if (i&(1<<j)) 
                if (x-dp[i^(1<<j)].second >= w[j])
                    dp[i] = min(dp[i], {dp[i^(1<<j)].first, dp[i^(1<<j)].second + w[j]});
                else 
                    dp[i] = min(dp[i], {dp[i^(1<<j)].first + 1, w[j]});
    cout << dp[(1<<n)-1].first;
    return 0;
}