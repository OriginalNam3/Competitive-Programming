// Problem: Parcels
// Contest: Google Coding Competitions - Coding Practice with Kick Start Session #2 - Kick Start 2022
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4a94/0000000000b55465
// Memory Limit: 1024 MB
// Time Limit: 15000 ms
// Date & Time: 2022-06-30 21:25:29
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent husbando <3

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

#define mp make_pair
#define f first
#define s second

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb emplace_back

#ifdef ORIGINAL_LOCAL
#include <bits/debug.h>
#else
#define dbg(...) 42
#endif

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

int dx[4] = {1, -1, -1, 1}, dy[4] = {1, -1, 1, -1};

void solve(){
	int n, m;
	cin >> n >> m;
	
	vector<vector<bool> > a(n + 2, vector<bool>(m + 2));
	for (int i = 1; i <= n; i++){
		str row;
		cin >> row;
		for (int j = 1; j <= m; j++){
			a[i][j] = row[j - 1] == '1';
		}
	}

	int sx[4] = {1, n, n, 1}, sy[4] = {1, m, 1, m};
	vector<vector<vector<int> > > dp(n + 2, vector<vector<int> > (m + 2, vector<int> (4, 1000)));
	for (int k = 0; k < 4; k++){
		for (int i = sx[k]; i > 0 && i <= n; i += dx[k]) {
			for (int j = sy[k]; j > 0 && j <= m; j += dy[k]){
				dp[i][j][k] = min(dp[i - dx[k]][j][k], dp[i][j - dy[k]][k]) + 1;
				if (a[i][j]) dp[i][j][k] = 0;
			}
		}
	}
	
	vector<vector<pair<int, int> > > mx(n + m, vector<pair<int, int> > (4));
	for (int i = 0; i < n + m; i++) mx[i][1].f = mx[i][2].s = mx[i][3].f = 1000;
	int mxd = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++){
		int d = min(min(dp[i][j][0], dp[i][j][1]), min(dp[i][j][2], dp[i][j][3]));
		mxd = max(mxd, d);
		if (i + j > mx[d][0].f + mx[d][0].s) mx[d][0].f = i, mx[d][0].s = j;
		if (i + j < mx[d][1].f + mx[d][1].s) mx[d][1].f = i, mx[d][1].s = j;
		if (i - j > mx[d][2].f - mx[d][2].s) mx[d][2].f = i, mx[d][2].s = j;
		if (i - j < mx[d][3].f - mx[d][3].s) mx[d][3].f = i, mx[d][3].s = j;
	}

	for (int d = mxd - 1; d >= 0; d--){
		if (mx[d][0].f + mx[d][0].s < mx[d + 1][0].f + mx[d + 1][0].s) mx[d][0].f = mx[d + 1][0].f, mx[d][0].s = mx[d + 1][0].s;
		if (mx[d][1].f + mx[d][1].s > mx[d + 1][1].f + mx[d + 1][1].s) mx[d][1].f = mx[d + 1][1].f, mx[d][1].s = mx[d + 1][1].s;
		if (mx[d][2].f - mx[d][2].s < mx[d + 1][2].f - mx[d + 1][2].s) mx[d][2].f = mx[d + 1][2].f, mx[d][2].s = mx[d + 1][2].s;
		if (mx[d][3].f - mx[d][3].s > mx[d + 1][3].f - mx[d + 1][3].s) mx[d][3].f = mx[d + 1][3].f, mx[d][3].s = mx[d + 1][3].s;
	}
	
	dbg(mx);
	dbg(n, m);
	
	int l = 0, r = mxd;
	while (l < r){
		int t = (l + r + 1)/2, cur = INT_MAX;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				dbg(n, m);
				int ncur = 0;
				for (int k = 0; k < 4; k++){
					ncur = max(ncur, abs(i - mx[t][k].f) + abs(j - mx[t][k].s));
				}
				dbg(i, j, ncur);
				cur = min(cur, ncur);
			}
		}
		dbg(l, r, cur);
		if (cur < t) r = t - 1;
		else l = t;
	}
	cout << l << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
	for (int i = 1; i <= t; i++){
    	cout << "Case #" << i << ": ";
    	solve();
	}
}
