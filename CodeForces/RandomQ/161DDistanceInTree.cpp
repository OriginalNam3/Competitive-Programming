// Problem: D. Distance in Tree
// Contest: Codeforces - VK Cup 2012 Round 1
// URL: https://codeforces.com/problemset/problem/161/D
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
typedef array<int, 3> qq;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

const int N = 50002;
int n, k;
vector<vi> g(N), dp(N, vi(501));
vi p(N);

void dfs(int u){
	dp[u][0] = 1;
	each(v, g[u]){
		if (v == p[u]) continue;
		p[v] = u;
		dfs(v);
		fr(i, 0, k){
			dp[u][i+1] += dp[v][i];
		}
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    fr(i, 0, n-1){
    	int a, b;
    	cin >> a >> b;
    	a--; b--;
    	g[a].pb(b);
    	g[b].pb(a);
    }
    p[0] = 0;
    dfs(0);
    // fr(i, 0, n){
    	// fr(j, 1, k+1){
    		// cout << dp[i][j] << " ";
    	// }
    	// cout << "\n";
    // }
    queue<int> q;
    q.push(0);
    ll ans = 0;
    while (!q.empty()){
    	int u = q.front();
    	q.pop();
    	ans += dp[u][k];
    	ll nans = 0;
		each(v, g[u]){
			if (v == p[u]) continue;
			fr(i, 1, k){
				nans += dp[v][k-i-1] * (dp[u][i] - dp[v][i-1]);
				// cout << dp[v][k-i-1] << " " << dp[u][i] << " " << dp[v][i-1] << "\n";
				// cout << i << " " << k - i << " at " << u << " " << v << " "<< ans << "\n";
			}
			q.push(v);
		}
		ans += nans/2;
    }
    cout << ans;
}
