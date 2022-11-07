// Problem: S2 - Tandem Bicycle
// Contest: DMOJ - CCC '16
// URL: https://dmoj.ca/problem/ccc16s2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-11-02 19:16:05
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
	int t, n;
	cin >> t >> n;
	vector<int> a(n), b(n);
	for (int &x: a) cin >> x;
	for (int &x: b) cin >> x;
	
	sor(a);
	if (t == 2) rsor(b);
	else sor(b);
	ll ans = 0;
	for (int i = 0; i < n; i++) ans += max(a[i], b[i]);
	
	cout << ans << "\n";
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
}
