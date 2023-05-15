#include <bits/stdc++.h>
using namespace std;

string str = "";
string res = "";
int minC = 1e9;
bool check(string s) {
    for (int i = 1; i<=s.size()/2; i++) {
        string s1 = s.substr(s.size() - i, i);
        string s2 = s.substr(s.size() - 2*i, i);
        if (s1 == s2) return false;
    }
    return true;
}

void backtrack(int len, int n) {
    int numC = count(str.begin(), str.end(), 'C');
    if(numC + (n - len) / 4 >= minC) return;
    if (len == n )
        if(numC < minC) {
            res = str;
            minC = numC;
        }
    for (char c = 'A'; c <= 'C'; c++)
        if(len == 0 || str[len - 1] != c) {
            str.push_back(c);
            if (check(str))
                backtrack(len+1, n);
            str.pop_back();
        }
}

int main()
{
    int n;
    cin>>n;
    backtrack(0, n);
    cout << res;
    return 0;
}