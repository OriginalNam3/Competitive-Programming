// Problem: D. Tokitsukaze and Meeting
// Contest: Codeforces - Codeforces Round #789 (Div. 2)
// URL: https://codeforces.com/contest/1678/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-08 15:35:40
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<int> row(n * m);
	vector<int> col(n * m);
	vector<bool> occ(m);
	if (s[0] - '0' == 1){
		occ[0] = 1;
		col[0]++;
	}
	for (int i = 1; i < n * m; i++){
		col[i] = col[i-1];
		if (s[i] - '0' == 1 && !occ[i % m]){
			occ[i%m] = 1;
			col[i]++;
		}
	}
	vector<int> emp(m);
	
	int j = -1;
	for (int i = 0; i < m; i++){
		if (i > 0) row[i] = row[i-1];
		if (s[i] - '0' == 1){
			row[i] = 1;
			j = i;
		}
	}
	
	
	for (int i = m; i < n * m; i++){
		if (s[i] - '0' == 1){
			j = i;
		}
		row[i] = row[i-m];
		if (i - j < m) row[i]++;
	}
	
	// vdebug(row) vdebug(col)
	
	for (int i = 0; i < n * m; i++){
		cout << row[i] + col[i] << " ";
	}
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
