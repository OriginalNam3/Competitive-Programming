// Problem: C. Chef Monocarp
// Contest: Codeforces - Educational Codeforces Round 97 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1437/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n;
	cin >> n;
	vi a(n);
	forn(i, 0, n){
		cin >> a[i];
	}
	sor(a);
	vector<vi> dp(2 * n, vi(n, INF));
	forn(i, 0, 2 * n){
		dp[i][0] = abs(i+1 - a[0]);
	}
	forn(j, 0, n-1) forn(i, 0, 2 * n) forn(k, i+1, 2 * n){
		dp[k][j+1] = min(dp[k][j+1], dp[i][j] + abs(k+1 - a[j+1]));
	}
	int mn = INF;
	forn(i, 0, 2 * n){
		mn = min(mn, dp[i][n-1]);
	}
	cout << mn << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while (q--){
    	solve();
    }
}
