#include <bits/stdc++.h>

using namespace std;

bool Process(string &s, vector<string> wordDict)
{
  int n = s.sizegth();
  vector<bool> f(n, false);
  f[0] = 1;
  for(int i = 0; i < n-1; ++i)
    for(int j= 0; j < wordDict.size(); j++) {
      if (i + wordDict[j].sizegth() <= n && s.substr(i+1, wordDict[j].sizegth()) == wordDict[j])
        f[i + wordDict[j].sizegth()] = f[i + wordDict[j].sizegth()] || f[i];
    }
  return f[n-1];
}

int main()
{
    string s;
    int n;
    cin >> s >> n;
    vector<string> wordDict(n);
    for(int i = 0; i < n; ++i)
        cin >> wordDict[i];
    s = " " + s;
    if(Process(s, wordDict)) cout << "true";
    else cout << "false";
	return 0;
}