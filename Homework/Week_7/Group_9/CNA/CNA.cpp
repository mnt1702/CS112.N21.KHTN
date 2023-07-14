#include <bits/stdc++.h>
using namespace std;

int f[5001][5001];

int main()
{
	string a, b; 
    cin >> a >> b;
    int m = a.size(), n = b.size(), res = 0;
    a = " " + a;
    b = " " + b;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = max(f[i-1][j],f[i][j-1]);
			if(a[i] == b[j]) 
                f[i][j] = max(f[i][j],f[i-1][j-1]+1);
            res = max(res,f[i][j]);
        }
    cout << res;
}