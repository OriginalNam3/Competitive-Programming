// Problem: D. Array and Operations
// Contest: Codeforces - Brogrammer Contest #2
// URL: https://codeforces.com/problemset/problem/1618/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Date & Time: 2022-04-28 20:08:13
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

void solve(){
	int n, k;
	cin >> n >> k;
	vi a(n);
	// set<int> b;
	// map<int, int> cnt;
	each(x, a) {
		cin >> x;
		// cnt[x]++;
		// b.insert(x);
	}
	sor(a);
	// vpi c;
	// while (!b.empty()){
		// c.pb(mp(*b.begin(), cnt[*b.begin()]));
		// b.erase(*b.begin());
	// }
	ll ans = 0;
	forn(i, n - k, n){
		ans += a[i-k] / a[i];
	}
	forn(i, 0, n - 2 * k){
		ans += a[i];
	}
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
