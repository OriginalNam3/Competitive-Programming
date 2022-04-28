// Problem: C. Journey
// Contest: Codeforces - 27-03-2022 TCP (Graphs)
// URL: https://codeforces.com/contest/721/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Date & Time: 2022-04-27 18:39:58
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


int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    // vector<vpi> g(n);
    vector<vpi> rg(n);
    rep(m){
    	int u, v, nt;
    	cin >> u >> v >> nt;
    	u--; v--;
    	// g[u].pb(mp(v, nt));
    	rg[v].pb(mp(u, nt));
    	// debug(v);
    }
    queue<int> q;
    q.push(0);
    vector<vll> dp(n, vll(n+1, INF));
    dp[0][1] = 0;

    forn(i, 1, n+1){
    	forn(u, 0, n){
    		each(p, rg[u]){
    			int v = p.f, nt = p.s;
	    		if (dp[v][i-1] + nt <= t){
	    			dp[u][i] = min(dp[u][i], dp[v][i-1] + nt);
	    		}
	    	}
    	}
    }
    rofn(i, 1, n + 1){
    	if (dp[n-1][i] <= t){
    		cout << i << "\n";
    		int u = n-1;
    		vi ans(1, n);
    		while (i > 0){
    			i--;
    			each(p, rg[u]){
    				int v = p.f, nt = p.s;
    				if (dp[v][i] == dp[u][i+1] - nt){
    					u = v;
    					break;
    				}
    			}
    			ans.pb(u+1);
    			if (u == 0) break;
    		}
    		rofn(j, 0, ans.size()){
    			cout << ans[j] << " ";
    		}
    		cout << "\n";
    		return 0;
    	}
    }
    cout << -1;
}
