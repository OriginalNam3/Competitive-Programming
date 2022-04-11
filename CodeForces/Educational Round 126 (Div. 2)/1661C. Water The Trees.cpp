// Problem: C. Water the Trees
// Contest: Codeforces - Educational Codeforces Round 126 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1661/problem/C
// Memory Limit: 256 MB
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
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb push_back

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define fors(i,a,b,s) for (int i = (a); i < (b); i+=s)
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
	vi h(n);
	int o = 0, mx = 0;
	forn(i, 0, n){
		cin >> h[i];
		mx = max(mx, h[i]);
	}
	ll th = 0;
	forn(i, 0, n){
		if ((mx - h[i]) % 2 == 1){
			o++;
		}
		th += (mx - h[i]);
		// cout << th << " : th\n";
	}
	th -= 3 * o;
	ll ans = 0;
	if (th <= 0){
		if (th == 0) ans = 1LL * 2 * o;
		if (th < 0) ans = 1ll * 2 * o - 1;
	}
	else ans = 2 * o + (2 * (th/3)) + th%3;
	mx++;
	th = 0; o = 0;
	forn(i, 0, n){
		if ((mx - h[i]) % 2 == 1){
			o++;
		}
		th += (mx - h[i]);
	}
	th -= 3 * o;
	// cout << th << " :th\n";
	if (th <= 0){
		if (th == 0) ans = min(ans, 1LL * 2 * o);
		else ans = min(ans, 1ll * 2 * o - 1);
	}
	else ans = min(ans, 2 * o + (2 * (th/3)) + th%3);
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
