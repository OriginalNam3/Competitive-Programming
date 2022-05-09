// Problem: B. Working out
// Contest: Codeforces - Codeforces Round #245 (Div. 1)
// URL: https://codeforces.com/problemset/problem/429/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-05 23:14:40
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

void solve(){
	
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vi> g(n, vi(m));
    forn(i, 0, n) forn(j, 0, m) cin >> g[i][j];
    vector<vi> lu(n, vi(m));
    lu[0][0] = g[0][0];
	forn(i, 0, n){
		if (i > 0) lu[i][0] = lu[i-1][0] + g[i][0];
		forn(j, 1, m){
			lu[i][j] = lu[i][j-1];
			if (i > 0) lu[i][j] = max(lu[i][j], lu[i-1][j]);
			lu[i][j] += g[i][j];
		}
	}
	// vdebug(lu[0]) vdebug(lu[1]) vdebug(lu[2])
	vector<vi> rd(n, vi(m));
    rd[n-1][m-1] = g[n-1][m-1];
	rofn(i, 0, n){
		if (i < n - 1) rd[i][m-1] = rd[i+1][m-1] + g[i][m-1];
		rofn(j, 0, m-1){
			rd[i][j] = rd[i][j+1];
			if (i < n - 1) rd[i][j] = max(rd[i][j], rd[i+1][j]);
			rd[i][j] += g[i][j];
		}
	}
	// vdebug(rd[0]) vdebug(rd[1]) vdebug(rd[2])
	vector<vi> ld(n, vi(m));
    ld[n-1][0] = g[n-1][0];
	rofn(i, 0, n){
		if (i < n - 1) ld[i][0] = ld[i+1][0] + g[i][0];
		forn(j, 1, m){
			ld[i][j] = ld[i][j-1];
			if (i < n - 1) ld[i][j] = max(ld[i][j], ld[i+1][j]);
			ld[i][j] += g[i][j];
		}
	}
	// vdebug(ld[0]) vdebug(ld[1]) vdebug(ld[2])
	vector<vi> ru(n, vi(m));
    ru[0][m-1] = g[0][m-1];
	forn(i, 0, n){
		if (i > 0) ru[i][m-1] = ru[i-1][m-1] + g[i][m-1];
		rofn(j, 0, m-1){
			ru[i][j] = ru[i][j+1];
			if (i > 0) ru[i][j] = max(ru[i][j], ru[i-1][j]);
			ru[i][j] += g[i][j];
		}
	}
	// vdebug(ru[0]) vdebug(ru[1]) vdebug(ru[2])
	int ans = 0;
	
	forn(i, 1, n - 1) forn(j, 1, m - 1){
		int nans = max(rd[i + 1][j] + ru[i][j + 1] + lu[i - 1][j] + ld[i][j - 1], rd[i][j + 1] + ru[i - 1][j] + lu[i][j - 1] + ld[i + 1][j]);
		// debug(nans)
		if (nans > ans){
			// debug(ans)
			ans = nans;
			
			// debug(i) debug(j)
		}
	}
	
	cout << ans;
}
