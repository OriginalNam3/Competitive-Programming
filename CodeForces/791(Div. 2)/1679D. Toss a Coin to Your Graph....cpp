// Problem: D. Toss a Coin to Your Graph...
// Contest: Codeforces - Codeforces Round #791 (Div. 2)
// URL: https://codeforces.com/contest/1679/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Date & Time: 2022-05-14 10:35:13
// 
// Powered by CP Editor (https://cpeditor.org)

// You either sink in the coom, or coom in the sink.

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

const int N = 2e5 + 5;

int n, m, cur, k;
vector<vector<int> > g;
vector<int> a(N), dp(N), vis(N);

void dfs(int u){
	if (dp[u] > 0) {
		vis[u] = 2;
		return;
	}
	vis[u] = 1;
	for (int v: g[u]){
		if (a[v] <= cur){
			if (vis[v] == 1){
				dp[u] = INF;
				continue;
			}
			dfs(v);
			dp[u] = max(dp[u], dp[v]);
		}
	}
	dp[u] += 1;
	vis[u] = 2;
}

bool search(){
	int mx = 0;
	for (int i = 0; i < n; i++){
		vis[i] = 0;
		dp[i] = 0;
	}
	for (int u = 0; u < n; u++){
		if (a[u] <= cur && vis[u] == 0){
			dfs(u);
			mx = max(mx, dp[u]);
		}
	}
	// vdebug(dp)
	return mx >= k;
}


int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    ll x; cin >> x;
    x = min(x, 1LL * n + 1);
    k = x;
    g.assign(n, vector<int> ());
    
    for (int i = 0; i < n; i++){
    	cin >> a[i];
    }
    
    for (int i = 0; i < m; i++){
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	g[u].pb(v);
    }
    
    int l = 0, r = 1e9 + 1;
    while (l < r){
    	cur = l + (r-l)/2;
    	dp.assign(n, 0);
    	if (search()){
    		r = cur;
    	}
    	else{
    		l = cur + 1;
    	}
    	// debug(l) debug(r)
    }
    cout << (l == 1e9 + 1 ? -1: l);
}
