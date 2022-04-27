// Problem: E2. Escape The Maze (hard version)
// Contest: Codeforces - Brogrammer Contest #1
// URL: https://codeforces.com/gym/379420/problem/E2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-04-24 19:33:13
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
template<class T> using V = vector<T>;
typedef array<int, 3> qq;

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
	vi x(k);
	each(p, x){
		cin >> p;
		p--;
	}
	
	vector<vi> g(n);
	forn(i, 0, n-1){
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}

	// forn(i, 0, n){
		// cout << d[i] << " ";
	// }
	// cout << "\n";
	queue<int> q;
	// swap(q, empty);
	q.push(0);
	vi t(n, 0);
	while (!q.empty()){
		int u = q.front();
		q.pop();
		// debug(u);
		each(v, g[u]){
			if (t[v] == 0 && v != 0){
				q.push(v);
				t[v] = t[u]+1;
			}	
		}
	}
	
	vi d(n, INF), c(n);
	forn(i, 0, k){
		q.push(x[i]);
		d[x[i]] = 0;
		c[x[i]] = i;
	}
	while (!q.empty()){
		int u = q.front();
		q.pop();
		each(v, g[u]){
			if (d[u] + 1 < d[v]){
				d[v] = d[u] + 1;
				q.push(v);
				c[v] = c[u];
			}
		}
	}
	
	set<int> ans;
	q.push(0);
	while (!q.empty()){
		int u = q.front();
		q.pop();
		if (d[u] <= t[u]){
			ans.insert(c[u]);
		}
		else {
			if (u != 0 && g[u].size() == 1){
				cout << "-1\n";
				return;
			}
			each(v, g[u]){
				if (t[v] > t[u]) q.push(v);
			}
		}
	}
	cout << ans.size() << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	solve();
    }
}