// Problem: D. Potion Brewing Class
// Contest: Codeforces - Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.com/contest/1654/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h> 
using namespace std;

int mod 998244353;
vector<vecrtor<pair<int, int>>> a;
vector<long long> b;
vector <

void dfs (int u, int p, int x, int y) {
	
}

int main() {
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		a.assign (n+5, vector<int> ());
		for (int i = 0; i < n-1; i++) {
			int i, j, x, y;
			cin >> i >> j >> x >> y;
			int d = gcd(x, y);
			x /= d;
			y /= d;
			a[i].push_back(make_pair(x, y));
			a[j].push_back(make_pair(y, x));
		}
		
		b.assign(n+5, 0);
		a[0].push_back(make_pair(1, 1));
		b[0] = 1;
		dfs (1, 0);
	}
}
