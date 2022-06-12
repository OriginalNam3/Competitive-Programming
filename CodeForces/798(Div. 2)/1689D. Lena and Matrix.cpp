// Problem: D. Lena and Matrix
// Contest: Codeforces - Codeforces Round #798 (Div. 2)
// URL: https://codeforces.com/contest/1689/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-10 22:58:56
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
#define dbg(...) 69420
#endif

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

int dx[] = {1, 1, -1, -1}, dy[] = {1, -1, 1, -1};

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<bool> > a(n + 1, vector<bool>(m + 1));
	for (int i = 0; i < n; i++){
		str row; cin >> row;
		for (int j = 0; j < m; j++) a[i + 1][j + 1] = row[j] == 'B';
	}
	
	int sx[] = {n, n, 1, 1}, sy[] = {m, 1, m, 1};
	
	vector<vector<vector<int> > > dp(n + 2, vector<vector<int> > (m + 2, vector<int> (4, -1)));
	for (int d = 0; d < 4; d++){
		for (int i = sx[d]; i <= n && i > 0; i -= dx[d]){
			for (int j = sy[d]; j <= m && j > 0; j -= dy[d]){
				// dbg(i, j);
				if (a[i][j]) dp[i][j][d] = 0;
				if (dp[i + dx[d]][j][d] != -1){
					dp[i][j][d] = max(dp[i][j][d], dp[i + dx[d]][j][d] + 1);
				}
				if (dp[i][j + dy[d]][d] != -1){
					dp[i][j][d] = max(dp[i][j][d], dp[i][j + dy[d]][d] + 1);
				}
				// dbg(dp[i][j][d]);
			}
		}
	}
	
	int mn = INT_MAX, x, y;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			int mx = max(max(dp[i][j][0], dp[i][j][1]), max(dp[i][j][2], dp[i][j][3]));
			dbg(i, j, mx);
			if (mx == -1) continue;
			if (mx < mn){
				x = i, y = j, mn = mx;
			}
		}
	}
	
	cout << x << " " << y << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
