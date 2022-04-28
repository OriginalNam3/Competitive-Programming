// Problem: C. Paint the Array
// Contest: Codeforces - Brogrammer Contest #2
// URL: https://codeforces.com/problemset/problem/1618/C
// Memory Limit: 256 MB
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
	int n;
	cin >> n;
	vll a(n);
	each(x, a) cin >> x;
	
	bool ok;
	int i = 2;
	ll g = a[0];
	while (i < n){
		g = gcd(g, a[i]);
		i += 2;
	}
	// debug(g);
	ok = true;
	forn(i, 0, n-1){
		if ((a[i] % g > 0 && a[i+1] % g > 0) || (a[i] % g == 0 && a[i+1] % g == 0)){
			ok = false;
			break;
		}
	}
	if (ok){
		cout << g << "\n";
		return;
	}
	i = 3;
	g = a[1];
	while (i < n){
		g = gcd(g, a[i]);
		i += 2;
	}
	// debug(g);
	ok = true;
	forn(i, 0, n-1){
		if ((a[i] % g > 0 && a[i+1] % g > 0) || (a[i] % g == 0 && a[i+1] % g == 0)){
			ok = false;
			break;
		}
	}
	if (ok){
		cout << g << "\n";
		return;
	}
	cout << "0\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
