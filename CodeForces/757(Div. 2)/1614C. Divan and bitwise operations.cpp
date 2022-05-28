// Problem: C. Divan and bitwise operations
// Contest: Codeforces - Brogrammer contest #something (I forgor)
// URL: https://codeforces.com/contest/1614/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-23 18:55:32
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
	int n, m;
	cin >> n >> m;
	vector<bool> cnt(31);
	for (int i = 0; i < m; i++){
		int l, r, x;
		cin >> l >> r >> x;
		for (int j = 0; j < 31; j++){
			if (x & 1) cnt[j] = 1;
			x >>= 1;
		}
	}
	
	int b = qpow(2, n - 1, mod), ans = 0;
	for (int i = 0; i < 31; i++){
		if (cnt[i]) ans = add(ans, mul(b, (1 << i)));
	}
	
	cout << ans << "\n";
	
	// vdebug(cnt)
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
