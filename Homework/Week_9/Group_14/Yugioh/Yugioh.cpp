#include <bits/stdc++.h>

using namespace std;
int a[201][201];
int n, k;

struct disjoint {
    int lab[201];
    disjoint() {
        for(int i = 1; i <= n; i++) 
            lab[i] = 0;
    }
    int root(int u) {
        return lab[u] <= 0 ? u : (lab[u] = root(lab[u]));
    }
    void join(int u, int v) { 
        if (lab[u] > lab[v]) swap(u, v); 
        if (lab[u] == lab[v]) lab[u]--; lab[v] = u;
    }
};

int process(int lim) {
    disjoint ds;
    int k = n;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            if (a[i][j] < lim) {
                int x = ds.root(i), y = ds.root(j);
                if (x != y) {
                    ds.join(x, y);
                    k--;
                }
            }
    return k;
}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    int l = 0, r = 1 << 16, m, res = 0;
    while (l <= r) {
        m = l + r >> 1;
        if (process(m) >= k) {
            res = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    cout << res;
    return 0;   
}