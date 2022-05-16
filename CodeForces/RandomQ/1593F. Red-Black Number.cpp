// Problem: F. Red-Black Number
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// URL: https://codeforces.com/contest/1593/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-06 21:06:53
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

#define mp make_pair
#define f first
#define s second

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
typedef vector<pi> vpi;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb push_back

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define fors(i,a,b,s) for (int i = (a); i < (b); i+=s)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

int qpow(int a, int b, int c){  // returns a^b % c
	if (c == 1) return 0;
	int res = 1;
	while (b > 0){
		if (b & 1) res = (1LL * res * a) % c;
		b >>= 1;
		a = (1LL * a * a) % c;
	}
	return res;
}

void solve(){
	int n, a, b;
	cin >> n >> a >> b;
	str x; cin >> x;
	bool dp[n + 1][n + 1][a][b];
	ll rec[n + 1][n + 1][a][b];
	memset(dp, 0, sizeof dp);
	memset(rec, 0, sizeof rec);
	dp[0][0][0][0] = 1;
	forn(i, 0, n) {
		// cout << i << "th row:\n";
		forn(j, 0, n) forn(k, 0, a) forn(l, 0, b){
			if (dp[i][j][k][l]){
				// debug(i)
				int na = (k + qpow(10, j, a) * (x[n - 1 - i] - '0')) % a;
				dp[i+1][j+1][na][l] = 1;
				rec[i+1][j+1][na][l] = (1LL << i) + rec[i][j][k][l];
				int nb = (l + qpow(10, i - j, b) * (x[n - 1 - i] - '0')) % b;
				dp[i+1][j][k][nb] = 1;
				rec[i+1][j][k][nb] = rec[i][j][k][l];
				// cout << k << " " << l << "\n";
			}
		}
	}
	for (int i = 0; i <= n / 2; i++){
		if (n/2 + i < n && dp[n][n/2 + i][0][0]){
			string ans = "";
			ll c = rec[n][n/2 + i][0][0];
			for (int j = 0; j < n; j++){
				if (c & 1) ans = "R" + ans;
				else ans = "B" + ans;
				c >>= 1;
			}
			cout << ans << "\n";
			return;
		}
		if (n/2 - i > 0 && dp[n][n/2 - i][0][0]){
			string ans = "";
			ll c = rec[n][n/2 - i][0][0];
			for (int j = 0; j < n; j++){
				if (c & 1) ans = "R" + ans;
				else ans = "B" + ans;
				c >>= 1;
			}
			cout << ans << "\n";
			return;
		}
	}
	cout << "-1\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
