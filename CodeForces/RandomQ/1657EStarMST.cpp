// Problem: E. Star MST
// Contest: Codeforces - Educational Codeforces Round 125 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1657/E
// Memory Limit: 512 MB
// Time Limit: 6000 ms
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

// const int INF = INT_MAX>>1;
const int MOD = 998244353;

int bpow(int a, int b){
	int res = 1, cur = a;
	while (b > 0){
		if (b & 1){
			res = (1LL * res * cur) % MOD;
		}
		b >>= 1;
		cur = (1LL * cur * cur) % MOD;
	}
	return res;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vi> nCr(n+1, vi(n+1));
    nCr[0][0] = 1;
    forn(i, 1, n+1){
    	nCr[i][0] = 1;
    	forn(j, 1, n+1){
    		nCr[i][j] = (1LL * nCr[i-1][j-1] + nCr[i-1][j]) % MOD;
    		// cout << nCr[i][j] << " ";
    	}
    	// cout << "\n";
    }
    vector<vi> dp(n, vi(k+1));
    // fr(i, 0, k+1){
    	// dp[0][i] = 1;
    // }
    dp[0][0] = 1;
    forn(j, 0, k) forn(i, 0, n){
    	// cout << i << " " << j << "\n";
    	int step = bpow(k - j, i), m = bpow(k - j, (i * (i-1))/2);
		forn(l, 0, n - i){
			dp[i+l][j+1] = (1LL * dp[i+l][j+1] + (1LL * dp[l][j] * ((1LL * nCr[n-l-1][i] * m) % MOD)) % MOD) % MOD;
			m = (1LL * m * step) % MOD;
		}
    }
    cout << dp[n-1][k];
}
