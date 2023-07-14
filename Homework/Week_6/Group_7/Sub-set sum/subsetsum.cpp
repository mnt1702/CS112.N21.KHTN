#include <iostream>

using namespace std;

int n, a[101], k, state[101];

void printSubset() {
    for(int i = 0; i < n; ++i)
        if(state[i]) cout << a[i] << ' ';
    cout << endl;
}

void Solve(int pos, int sum) {
    if(pos == n) {
        if(sum == k) printSubset();
        return;
    }
    for(int i = 1; i >= 0; --i) {
        state[pos] = i;
        sum += i * a[pos];
        if(sum <= k) Solve(pos+1, sum);
        sum -= i * a[pos];
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i) 
        cin >> a[i];
    cin >> k;
    Solve(0, 0);
}