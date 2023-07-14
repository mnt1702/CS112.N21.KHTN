#include <bits/stdc++.h>

using namespace std;

vector<int> edge[100001];
int cost[100001];
int n, m, res = 0;

void Dijkstra(int u) {
    cost[u] = 1;
    for(int v: edge[u]) {
        Dijkstra(v);
        cost[u] = max(cost[u], cost[v]+1);
    }
    res = max(res, cost[u]);
}

int main()
{
    cin >>n >>m;
    for(int i = 1; i <= m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        edge[v1].push_back(v2);
    }
    for(int i = 1; i <= n; i++) 
        if(cost[i] == 0) Dijkstra(i);
    cout << res-1;
    return 0;
}