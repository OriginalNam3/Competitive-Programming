// Problem: E. Gardener and Tree
// Contest: Codeforces - Brogrammer Contest #3
// URL: https://codeforces.com/contest/1593/problem/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Date & Time: 2022-04-29 19:30:58
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

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n, k;
	cin >> n >> k;
	vector<vi> g(n);
	vi cnt(n);
	rep(n-1){
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].pb(v);
		g[v].pb(u);
		cnt[u]++; cnt[v]++;
	}
	if (n == 1){
		cout << "0\n";
		return;
	}
	
	vi d(n);
	set<pi> q;
	forn(i, 0, n){
		if (g[i].size() == 1){
			q.insert(mp(1, i));
			d[i] = 1;
		}
	}
	while (!q.empty()){
		int u = q.begin()->s;
		q.erase(mp(d[u], u));
		// debug(u); 
		// debug(cnt[u]); debug(d[u]);
		if (cnt[u] > 1){
			continue;
		}
		cnt[u]--;
		each(v, g[u]){
			if (cnt[v] > 1){
				pi e = mp(d[v], v);
				auto it = q.find(e);
				if (it != q.end()){
					q.erase(e);
				}
				d[v] = d[u] + 1;
				q.insert(mp(d[v], v));
			}
			if (cnt[v] >= 1) cnt[v]--;
		}
	}
	// each(x, d) cout << x << " ";
	// cout << "\n";
	sor(d);
	int j = 0;
	forn(i, 1, k+1){
		while (j < n && d[j] == i){
			j++;
		}
		if (j == n) break;
	}
	
	cout << n - j << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
