// Problem: E - Takahashi and Animals
// Contest: AtCoder - Panasonic Programming Contest 2022(AtCoder Beginner Contest 251)
// URL: https://atcoder.jp/contests/abc251/tasks/abc251_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-17 16:06:46
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

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	vector<vector<ll> > dp(n, vector<ll> (2));
	dp[0][0] = INT_MAX;
	dp[0][1] = a[0];
	for (int i = 1; i < n - 1; i++){
		dp[i][0] = dp[i-1][1];
		dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + a[i];
	}
	ll ans = min(dp[n-2][1], dp[n-2][0] + a[n-1]);
	dp[0][0] = a[n-1];
	dp[0][1] = INT_MAX;
	for (int i = 1; i < n - 1; i++){
		dp[i][0] = dp[i-1][1];
		dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + a[i];
	}
	ans = min(ans, min(dp[n-2][0], dp[n-2][1]));
	cout << ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
