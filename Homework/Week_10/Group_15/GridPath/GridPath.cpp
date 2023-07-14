#include <bits/stdc++.h>

using namespace std;

string str_inp;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int res = 0;
bool accept[7][7];

void Process(int x, int y, int size) {
    if (x == 6 && y == 0) {
        res += size == 49;
        return;
    }
    if ((y == 0 || accept[x][y - 1]) && (y == 6 || accept[x][y + 1]) && (x > 0 && !accept[x - 1][y]) && (x < 6 && !accept[x + 1][y])) return;
    if ((y > 0 && !accept[x][y - 1]) && (y < 6 && !accept[x][y + 1]) && (x == 0 || accept[x - 1][y]) && (x == 6 || accept[x + 1][y])) return;
    accept[x][y] = true;
    if (str_inp[size - 1] == '?') {
        for(int i = 0; i < 4; ++i) {
            int u = x + dx[i], v = y + dy[i];
            if (0 <= u && u < 7 && 0 <= v && v < 7 && !accept[u][v]) Process(u, v, size + 1);
        }
    } else {
        switch(str_inp[size - 1]) {
            case 'U': {
                if (x - 1 >= 0 && !accept[x - 1][y]) Process(x - 1, y, size + 1);
                break;
            }

            case 'D': {
                if (x + 1 <= 6 && !accept[x + 1][y]) Process(x + 1, y, size + 1);
                break;
            }

            case 'L': {
                if (y - 1 >= 0 && !accept[x][y - 1]) Process(x, y - 1, size + 1);
                break;
            }

            case 'R': {
                if (y + 1 <= 6 && !accept[x][y + 1]) Process(x, y + 1, size + 1);
                break;
            }
        }
    }
    accept[x][y] = false;
}

int main() {
    cin >> str_inp;
    Process(0, 0, 1);
    cout << res;
    return 0;
}