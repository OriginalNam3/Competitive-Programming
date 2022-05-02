// Problem: D. Martial Arts Tournament
// Contest: Codeforces - Educational Codeforces Round 121 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1626/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-01 20:50:05
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

const int N = 200005;

int diff[N];

void solve(){
	int n;
	cin >> n;
	vi a(n);
	each(x, a) cin >> x;
	if (n == 1){
		cout << "2\n";
		return;
	}
	sor(a);
	vi pre(n);
	forn(i, 1, n){
		if (a[i] != a[i-1]){
			pre[i] = i;
		}
		else{
			pre[i] = pre[i-1];
		}
	}
	// vdebug(pre);
	int len = n, x = 1, nans = 0;
	while (x < len) x <<= 1;
	nans = x - len;
	int ans = 2 * n;
	for(int mid = 1; mid <= n; mid <<= 1) forn(i, 0, n){
		if (pre[i] != i) continue;
		
		nans = 0;
		len = i;
		// debug(len);
		nans += diff[i];
		
		len = pre[min(n-1, i + mid)] - i;
		// debug(len);
		// debug(i); debug(mid);
		nans += diff[len];
		
		len = n - pre[min(n-1, i+mid)];
		// debug(len);
		nans += diff[len];
		// debug(nans);
		ans = min(ans, nans);
	}
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int p = 1;
    forn(i, 0, N){
    	diff[i] = p - i;
    	if (i == p) p *= 2;
    }
    int t;
    cin >> t;
    while (t--) solve();
}
