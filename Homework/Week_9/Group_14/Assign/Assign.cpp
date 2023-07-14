#include <bits/stdc++.h>

using namespace std;

int dist[201][201], n, match[201];
bool visited[201];

bool DFS(int u, long long Max) {
    for(int v = 0; v < n; ++v)
        if (!visited[v] && Max >= dist[u][v]) {
            visited[v] = true;
            if (match[v] == -1 || DFS(match[v], Max)) {
                match[v] = u;
                return true;
            }
        }
    return false;
}

bool process(long long Max) {
    vector<int> temp;
    for(int u = 0; u < n; ++u) 
        temp.push_back(u);
    for(int v = 0; v < n; ++v) 
        match[v] = -1;
    int match = 0;
    while(true) {
        bool s = true;
        for(int v = 0; v < n; ++v) 
            visited[v] = false;
        for(int i = temp.size() - 1; i >= 0; --i)
            if (DFS(temp[i], Max)) {
                swap(temp[i], temp.back());
                temp.pop_back();
                ++match;
                s = false;
            }
        if(s) break;
    }
    return match == n;
}

int main() {
    cin >> n;
    long long Max = 0, Min = pow(10, 10);
    for(int u = 0; u < n; ++u)
        for(int v = 0; v < n; ++v) {
            cin >> dist[u][v];
            Max = max(Max, 1LL * dist[u][v]);
            Min = min(Min, 1LL * dist[u][v]);
        }
    long long res = 0;
    while (Min <= Max) {
        long long Mid = Max - (Max - Min) / 2;
        if (process(Mid)) {
            res = Mid;
            Max = Mid - 1;
        } else Min = Mid + 1;
    }
    cout << res;
    return 0;
}