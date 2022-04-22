// Problem: Jump to Sibling
// Contest: CodeChef - CodeChef Starters 35 Division 4 (Rated)
// URL: https://www.codechef.com/START35D/problems/JS
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	int n;
	cin >> n;
	vi a(n);
	each(x, a) cin >> x;
	vector<vi> jump(n, vi(2));
	int e = 1, o = 1;
	forn(i, 0, n){
		if (e == i) e++;
		if (o == i) o++;
		while (e < n + 1 && a[e] % 2) e++;
		while (o < n + 1 && !(a[o] % 2)) o++;
		if (a[i] % 2){
			jump[i][0] = o;
			jump[i][1] = e;
		}
		else{
			jump[i][1] = o;
			jump[i][0] = e;
		}
	}
	vector<vi> dp(2*n, vi(2, INT_MAX));
	dp[0][0] = dp[0][1] = 0;
	forn(i, 0, n-1){
		if (dp[i][0] != INT_MAX){
			dp[jump[i][0]][0] = min(dp[jump[i][0]][0], dp[i][0]+1);
			dp[jump[i][1]][1] = min(dp[jump[i][1]][1], dp[i][0]+1);
		}
		if (dp[i][1] != INT_MAX){
			dp[jump[i][0]][1] = min(dp[jump[i][0]][1], dp[i][1]+1);
		}
	}
	cout << min(dp[n-1][0], dp[n-1][1]) << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
