// Problem: D. Counting Arrays
// Contest: Codeforces - Educational Codeforces Round 138 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1749/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Date & Time: 2022-11-03 11:55:09
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
	ll n, m;
	cin >> n >> m;
	dbg(n, m);
	
	// all non ambiguous arrays have removal sequence [1, 1, ..., 1] 
	// so for all non ambiguous arrays all ai is divisible by primes multiplied
	
	vector<bool> prime(n + 1, 1);
	for (int i = 2; i * i <= n; i++){
		if (prime[i]){
			for (int j = i; j * i <= n; j++){
				prime[i * j] = 0;
			}
		}
	}
	
	int sum = 0, cnt = 1, ans = 0, cur = 1;
	for (int i = 1; i <= n; i++){
		cur = mul(cur, m % mod);
		ans = add(ans, cur);
	}
	ll fact = 1;
	for (int i = 1; i <= n; i++){
		if (prime[i]) fact *= i;
		if (fact > m){
			break;
		}
		cnt = mul(cnt, (1LL * m / fact) % mod);
		sum = add(sum, cnt);
	}
	ans = (1LL * ans + mod - sum) % mod;
	
	cout << ans;
	
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
}
