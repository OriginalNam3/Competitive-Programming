// Problem: The Rumbling
// Contest: CodeChef - Practice
// URL: https://www.codechef.com/problems/RUMBLING
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double db;
typedef string str;

#define mp make_pair
#define f first
#define s second

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<long long int> vll;
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
#define debug(x) cout << #x << " = " << x << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n;
	cin >> n;
	str s;
	cin >> s;
	ll x, y;
	cin >> x >> y;
	vll w(n), e(n);
	ll wsum = 0, esum = 0;
	forn(i, 0, n){
		if(s[i] == 'S'){
			w[i] = min(x, 3*y);
			e[i] = min(y, 3*x);
		}
		if (s[i] == 'N'){
			w[i] = min(y, 3*x);
			e[i] = min(x, 3*y);
		}
		if (s[i] == 'E'){
			w[i] = 2 * min(x, y);
		}
		if (s[i] == 'W'){
			e[i] = 2 * min(x, y);
		}
		wsum += w[i];
	}
	ll ans = wsum;
	forn(i, 0, n){
		esum += e[i]; wsum -= w[i];
		ans = min(ans, wsum + esum);
	}
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	solve();
    }
}
