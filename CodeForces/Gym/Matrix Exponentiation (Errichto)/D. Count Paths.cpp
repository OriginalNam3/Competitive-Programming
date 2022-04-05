// Problem: D. Count Paths
// Contest: Codeforces - Matrix Exponentiation
// URL: https://codeforces.com/gym/102644/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int g[n][n];
    memset(g, 0, sizeof g);
    forn(i, 0, m){
    	int a, b;
    	cin >> a >> b;
    	a--; b--;
    	g[a][b] = 1;
    }
    int res[n][n];
    memset(res, 0, sizeof res);
    forn(i, 0, n) forn(j, 0, n){
    	if (i == j){
    		res[i][j] = 1;
    	}
    }
    while (k > 0){
    	if (k & 1){
    		int product[n][n];
    		memset(product, 0, sizeof product);
    		forn(i, 0, n) forn(j, 0, n) forn(k, 0, n){
    			product[i][k] = add(product[i][k], mul(res[i][j], g[j][k]));
    		}
    		forn(i, 0, n) forn(j, 0, n){
    			res[i][j] = product[i][j];
    		}
    	}
    	int product[n][n];
    	memset(product, 0, sizeof product);
    	forn(i, 0, n) forn(j, 0, n) forn(k, 0, n){
    		product[i][k] = add(product[i][k], mul(g[i][j], g[j][k]));
    	}
    	forn(i, 0, n) forn(j, 0, n){
    		g[i][j] = product[i][j];
    	}
    	// forn(i, 0, n){
	    	// forn(j, 0, n) cout << g[i][j] << " ";
	    	// cout << "\n";
	    // }
	    // cout << "\n";
    	k >>= 1;
    }
    int ans = 0;
    forn(i, 0, n) forn(j, 0, n){
    	ans = add(ans, res[i][j]);
    }
    cout << ans;
}
