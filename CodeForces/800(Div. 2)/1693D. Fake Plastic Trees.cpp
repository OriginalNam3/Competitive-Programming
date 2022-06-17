// Problem: D. Fake Plastic Trees
// Contest: Codeforces - Goodbye Exams (TK L)
// URL: https://codeforces.com/contest/1693/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-06-17 21:25:54
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

int ans;
vector<vector<int> > g;
vector<pair<ll, ll> > a;

ll dfs(int u){
	ll res = 0;
	for (int v: g[u]){
		res += dfs(v);
	}
	if (res == 0){
		ans++;
		return a[u].s;
	}
	if (res < a[u].f){
		ans++;
		return a[u].s;
	}
	return min(a[u].s, res);
}

void solve(){
	int n;
	cin >> n;
	g.assign(n, vector<int>());
	for (int i = 1; i < n; i++){
		int p; cin >> p;
		p--;
		g[p].pb(i);
	}
	
	a.assign(n, pair<ll, ll>(0, 0));
	for (int i = 0; i < n; i++){
		cin >> a[i].f >> a[i].s;
	}
	
	ans = 0;
	dfs(0);
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while (t--)
    solve();
}
