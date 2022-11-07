// Problem: E. Placing Jinas
// Contest: Codeforces - Codeforces Global Round 21
// URL: https://codeforces.com/problemset/problem/1696/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-26 18:28:47
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

int fact[1000005], rfact[1000005];

int qpow(int a, int b){  // returns a^b % c
	int res = 1;
	while (b > 0){
		if (b & 1) res = (1LL * res * a) % mod;
		b >>= 1;
		a = (1LL * a * a) % mod;
	}
	return res;
}

int nCr(int n, int r){
	if (r < 0){
		return 0;
	}
	if (r == 0){
		return 1;
	}
	int res = fact[n];
	res = mul(res, rfact[n - r]);
	res = mul(res, rfact[r]);
	return res;
}

void solve(){
	fact[0] = 1;
	for (int i = 1; i < 1000005; i++){
		fact[i] = mul(fact[i-1], i);
		rfact[i] = qpow(fact[i], mod-2);
	}
	
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int &x: a) cin >> x;
	
	int ans = 0;
	for (int i = 0; i < n + 1; i++){
		ans = add(ans, nCr(a[i] + i, a[i] - 1));
		dbg(a[i] + i, a[i] - 1, nCr(a[i] + i, a[i] - 1));
	}
	
	cout << ans;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
