// Problem: F - Keep Connect
// Contest: AtCoder - UNIQUE VISION Programming Contest 2022（AtCoder Beginner Contest 248）
// URL: https://atcoder.jp/contests/abc248/tasks/abc248_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-15 13:34:38
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

int mod;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n;
	cin >> n >> mod;
	
	int dp[n + 1][n + 3][2];
	memset(dp, 0, sizeof dp);
	dp[0][0][0] = dp[0][1][1] = 1;
	
	for (int i = 1; i < n; i++){
		for (int j = 0; j < n; j++){
			dp[i][j][0] = add(dp[i][j][0], add(dp[i - 1][j][0], dp[i - 1][j][1]));
			dp[i][j + 1][0] = add(dp[i][j + 1][0], mul(dp[i - 1][j][0], 3));
			dp[i][j + 1][1] = add(dp[i][j + 1][1], dp[i - 1][j][1]);
			dp[i + 1][j + 2][0] = add(dp[i + 1][j + 2][0], mul(dp[i - 1][j][0], 2));
			dp[i + 1][j + 3][1] = add(dp[i + 1][j + 3][1], mul(dp[i - 1][j][0], 2));
		}
	}
	for (int i = 1; i < n; i++){
		dbg(dp[n-1][i][0], dp[n-1][i][1]);
		cout << dp[n-1][i][0] << " ";
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
