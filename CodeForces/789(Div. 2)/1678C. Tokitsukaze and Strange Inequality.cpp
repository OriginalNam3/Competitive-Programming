// Problem: C. Tokitsukaze and Strange Inequality
// Contest: Codeforces - Codeforces Round #789 (Div. 2)
// URL: https://codeforces.com/contest/1678/problem/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// Date & Time: 2022-05-08 15:35:40
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
	int n;
	cin >> n;
	vi a(n);
	each(x, a) cin >> x;
	vector<vi> rcnt(n+1, vi(n+1)); // counts numbers less than j after i
	rofn(i, 1, n+1){
		forn(j, 1, n+1){
			rcnt[i-1][j] = rcnt[i][j];
		}
		forn(j, a[i-1]+1, n + 1){
			rcnt[i-1][j]++;
		}
		// vdebug(rcnt[i])
	}
	
	vector<vi> lcnt(n + 1, vi(n+1));
	forn(i, 0, n){
		forn(j, 1, n + 1){
			lcnt[i + 1][j] = lcnt[i][j];
		}
		forn(j, a[i] + 1, n + 1){
			lcnt[i+1][j]++;
		}
		// vdebug(lcnt[i])
	}
	
	// vdebug(lcnt[0]) vdebug(rcnt[0])
	ll ans = 0;
	
	forn(i, 0, n){
		forn(j, i + 1, n){
			ans += 1LL * lcnt[i][a[j]] * rcnt[j+1][a[i]];
		}
	}
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
