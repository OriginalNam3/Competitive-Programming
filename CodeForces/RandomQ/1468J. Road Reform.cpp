// Problem: J. Road Reform
// Contest: Codeforces - 2020-2021 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules)
// URL: https://codeforces.com/problemset/problem/1468/J
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Date & Time: 2022-04-30 11:20:51
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

const int mod = 1e9 + 7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

const int N = 2e5 + 3;

vi point(N);
vi sz(N, 1);

int dfs(int u){
	if (point[u] == u) return u;
	return dfs(point[u]);
}

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vb in(n);
	vector<pair<int, pair<int, int> > > a;
	
	rep(m){
		int u, v, c;
		cin >> u >> v >> c;
		u--; v--;
		// debug(u) debug(v)
		a.pb(mp(c, mp(u, v)));
	}
	
	sor(a);
	int cnt = 0, i = 0;
	ll ans = 0;
	
	forn(i, 0, n){
		point[i] = i;
	}
	
	forn(i, 0, m){
		int c = a[i].f, u = dfs(a[i].s.f), v = dfs(a[i].s.s);
		if (u == v) continue;
		if (sz[u] > sz[v]) swap(u, v);
		point[u] = v;
		sz[v] += sz[u];
		if (c > k) ans += c - k;
	}

	if (ans == 0){
		ans = INT_MAX;
		forn(i, 0, m){
			ans = min(ans, 1LL * abs(a[i].f - k));
		}
	}
	cout << ans << "\n";
}

int main (){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
