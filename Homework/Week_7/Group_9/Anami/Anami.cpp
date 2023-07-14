#include <iostream>

using namespace std;

int f[3001][3001], mod = 1e9 + 7;

int Solve(int num, int sum) {
    if (sum > num) return 0;
    if (num == sum) return 1;
    if (num == 0 || sum == 0) return 0;
    if (f[num][sum]) return f[num][sum];
    f[num][sum] = (Solve(num - 1, sum - 1) + Solve(num, sum * 2)) % mod;
    return f[num][sum];
}

int main() {
    int n, S;
    cin >> n >> S;
    cout << Solve(n, S);
    return 0;
}