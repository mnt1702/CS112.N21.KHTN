#include <bits/stdc++.h>

using namespace std;

void solver(int n, int m, int* a) {
    sort(a, a + n);
    int max_r = (a[n- 1] - a[0] + 1) / 2;
    for(int r = 1; r <=  max_r; r++) {
        int num = 0, last = -1;
        for(int i = 0; i <= n; ++i)
            if (a[i] > last) {
                ++num;
                last = a[i] + 2*r;
            }
        if (num <= m) {
            cout << r;
            return;
        }
    }
    cout << 0;
    return;
}

int main() {
    int n, m, a[1000];
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    solver(n, m, a);
    return 0;
}