#include <bits/stdc++.h>

using namespace std;

struct Pointer {
    int x, y;
    bool operator < (const Pointer &other) {
        if (x + y != other.x + other.y) return x + y < other.x + other.y;
        return abs(x - y) < abs(other.x - other.y);
    }
};

int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[8] = {-1, 1, 0, -1, 1, 0, -1, 1};

vector<Pointer> P;
int a[206][206], m, n;
int res[206][206];

bool check(int u, int v)
{
    return (1 <= u && u <= m && 1 <= v && v <= n);
}

bool Solve(int pos) {
    if (pos >= (int) P.size()) {
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) cout << res[i][j] << ' ';
            cout << '\n';
        }
        return true;
    }

    int x = P[pos].x, y = P[pos].y;
    for(int c = 0; c < 2; ++c) {
        res[x][y] = c;

        bool flag = true;
        for(int i = 0; i < 8; ++i) {
            int u = x + dx[i];
            int v = y + dy[i];
            if (check(u, v)) flag &= a[u][v] >= res[x][y];
        }

        if (!flag) continue;

        for(int i = 0; i < 8; ++i) {
            int u = x + dx[i];
            int v = y + dy[i];
            if (check(u, v)) a[u][v] -= res[x][y];
        }

        flag = true;
        if (x > 1 && y > 1) flag &= a[x - 1][y - 1] == 0;
        if (x == m && y > 1) flag &= a[x][y - 1] == 0;
        if (y == n && x > 1) flag &= a[x - 1][y] == 0;
        if (x == m && y == n) flag &= a[x][y] == 0;

        if (flag)
            if (Solve(pos + 1)) return true;

        for(int i = 0; i < 8; ++i) {
            int u = x + dx[i];
            int v = y + dy[i];
            if (check(u, v)) a[u][v] += res[x][y];
        }
    }
    return false;
}

int main() {
    cin >> m >> n;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            P.push_back({i, j});
        }
    sort(P.begin(), P.end());
    Solve(0);
    return 0;
}