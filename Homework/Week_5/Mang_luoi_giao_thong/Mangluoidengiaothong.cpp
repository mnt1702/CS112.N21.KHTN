#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> city[100001];
int check[100001];

int BFS(int s) {
    check[s] = 1;
    queue<int> Q; 
    Q.push(s);
    int num = 0;
    while (!Q.empty()) {
        int u = Q.front(); 
        Q.pop();
        ++num;
        for(int v: city[u])
            if (check[v] == 0) {
                check[v] = 1;
                Q.push(v);
            }
    }
    return num;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        city[u].push_back(v);
        city[v].push_back(u);
    }

    long long res = 0;
    for(int s = 1; s <= n; ++s)
        if (check[s] == 0) {
            int num = BFS(s);
            res += 1LL  * num * (n - num) ;
        }

    cout << res / 2;

    return 0;
}