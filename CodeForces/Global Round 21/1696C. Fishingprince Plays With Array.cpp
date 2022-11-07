// Problem: C. Fishingprince Plays With Array
// Contest: Codeforces - Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-25 15:45:17
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
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (ll &x: a) cin >> x;
	int k;
	cin >> k;
	vector<ll> b(k);
	for (ll &x: b) cin >> x;
	
	bool ok = true;
	ll cur = 0, pow = 1, cnt = 0;
	vector<pair<ll, ll> > c, d;
	
	for (int i = 0; i < n; i++){
		int x = 1;
		while (a[i] % m == 0){
			a[i] /= m;
			x *= m;
		}
		if (cur != a[i]){
			c.pb(mp(cur, cnt));
			cur = a[i];
		}
		cnt += x;
	}
	c.pb(mp(cur, cnt));
	
	cur = 0, pow = 1, cnt = 0;
	for (int i = 0; i < k; i++){
		int x = 1;
		while (b[i] % m == 0){
			b[i] /= m;
			x *= m;
		}
		if (cur != b[i]){
			d.pb(mp(cur, cnt));
			cur = b[i];
		}
		cnt += x;
	}
	d.pb(mp(cur, cnt));
	dbg(c, d);
	
	if (c.size() != d.size()){
		ok = false;
	}
	for (int i = 0; i < c.size(); i++){
		if (c[i].f != d[i].f || c[i].s != d[i].s){
			ok = false;
			break;
		}
	}
	
	cout << (ok ? "Yes\n": "No\n");
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while (t--)
    solve();
}
