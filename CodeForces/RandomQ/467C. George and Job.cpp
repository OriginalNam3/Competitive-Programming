// Problem: C. George and Job
// Contest: Codeforces - Codeforces Round #267 (Div. 2)
// URL: https://codeforces.com/problemset/problem/467/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-29 19:40:27
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
#define pb push_back

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	vector<ll> pref(n + 1);
	for (int i = 1; i <= n; i++){
		pref[i] += pref[i-1] + a[i-1];
	}
	
	vector<vector<ll> > dp(k + 1, vector<ll> (n + 1));
	ll ans = 0;
	for (int i = 1; i <= k; i++){
		ll mx = 0;
		for (int j = m; j <= n; j++){
			mx = max(mx, dp[i-1][j - m]);
			dp[i][j] = mx + pref[j] - pref[j - m];
			ans = max(ans, dp[i][j]);
		}
	}
	
	cout << ans;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
