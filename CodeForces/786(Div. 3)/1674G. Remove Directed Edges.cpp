// Problem: G. Remove Directed Edges
// Contest: Codeforces - Codeforces Round #786 (Div. 3)
// URL: https://codeforces.com/contest/1674/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-02 15:35:10
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

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

const int N = 200005;

vi d(N);
vector<vi> g(N);
vi in(N), out(N);

int dfs(int u){
	if (d[u] > 0) return d[u];
	if (out[u] == 1){
		d[u] = 1;
		return d[u];
	}
	
	d[u] = 1;
	each(v, g[u]){
		if (in[v] <= 1) continue;
		d[u] = max(d[u], dfs(v) + 1);
	}
	
	return d[u];
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    rep(m){
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	g[u].pb(v);
    	in[v]++;
    	out[u]++;
    }
    
    int ans = 1;
    forn(i, 0, n){
    	if (d[i] == 0) dfs(i);
    	ans = max(ans, d[i]);
    }
    cout << ans;
}
