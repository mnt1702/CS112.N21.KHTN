#include <bits/stdc++.h>

using namespace std;

map<string, int> popular;
int n, res;

int main() {
    string name1, repost, name2;
    cin >> n;
    res = 1;
    popular["polycarp"] = 1;
    for(int i = 0; i < n; i++) {
        cin >> name1 >> repost >> name2;
        for(int j = 0; j < name1.size(); j++) 
            name1[j] = tolower(name1[j]);
        for(int j = 0; j < name2.size(); j++) 
            name2[j] = tolower(name2[j]);
        popular[name1] = popular[name2] + 1;
        if(popular[name1] > res) res = popular[name1];
    }
    cout << res;
    return 0;
}
   