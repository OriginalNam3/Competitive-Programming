// Problem: E - Distance Sequence
// Contest: AtCoder - NOMURA Programming Contest 2022（AtCoder Beginner Contest 253）
// URL: https://atcoder.jp/contests/abc253/tasks/abc253_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-04 21:07:53
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

const int mod = 998244353;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

int qpow(int a, int b, int c){  // returns a^b % c
	int res = 1;
	while (b > 0){
		if (b & 1) res = (1LL * res * a) % c;
		b >>= 1;
		a = (1LL * a * a) % c;
	}
	return res;
}

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	
	if (k == 0){
		cout << qpow(m, n, mod);
		return;
	}
	
	vector<int> dp(m + 1), pref(m + 1);
	
	for (int i = 1; i <= m; i++){
		pref[i] = pref[i-1] + 1;
	}
	
	for (int i = 1; i < n; i++){
		for (int j = 1; j <= m; j++){
			dp[j] = 0;
			if (j - k > 0){
				dp[j] = pref[j-k];
			}
			if (j + k <= m){
				dp[j] = add(dp[j], (1LL * mod + pref[m] - pref[j + k - 1]) % mod);
			}
		}
		for (int j = 1; j <= m; j++){
			pref[j] = add(pref[j-1], dp[j]);
		}
	}
	
	cout << pref[m];
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
