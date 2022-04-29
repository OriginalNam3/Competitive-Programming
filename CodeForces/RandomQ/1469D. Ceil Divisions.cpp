// Problem: D. Ceil Divisions
// Contest: Codeforces - Educational Codeforces Round 101 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1469/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-04-29 15:56:29
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
	int n; cin >> n;
	vpi ans;
	int j = n;
	rofn(i, 2, n){
		if (1LL * (i - 1) * (i - 1) < 1LL * j && 1LL * i * i >= 1LL * j){
			ans.pb(mp(j, i));
			ans.pb(mp(j, i));
			j = i;
		}
		else{
			ans.pb(mp(i, j));
		}
	}
	cout << ans.size() << "\n";
	each(p, ans){
		cout << p.f << " " << p.s << "\n";
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
