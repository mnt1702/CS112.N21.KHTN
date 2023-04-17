#include <bits/stdc++.h>

using namespace std;

vector<int> t(9);
vector<string> pos(9);

int time(vector<int> light, int i){
	int a = 9;
	int res = 0;
	while (--a >= 0){
		int tmp = i%3;
		i/=3;
		res += t[a] * tmp;
		for (char ch : pos[a]){
			int k = ch - '1';
			light[k] = (light[k] + tmp) % 3;
		}  
	}
	bool flag = true;
	for (int j = 0; j < 9; j++){
		if (light[j] != 0) flag = false;
	}
	if (flag) return res;
	else return 1e9;
	
}

int main()
{	
	for (int i = 0; i<9; i++)
		cin >> t[i] >> pos[i]; 
	string s;
	cin >> s;

	vector<int> light(9);
	for (int i = 0; i < 9; i++){
		if (s[i] == 'X') light[i] = 0;
		else if (s[i] == 'V') light[i] = 1;
		else light[i] = 2; 
	}
	int res = 1e9 - 1;
	for (int i = 0; i < pow(3,9); i++)
		res = min(res, time(light, i));
	if (res == 1e9 - 1) cout << -1;
	else cout << res;
	return 0;
}