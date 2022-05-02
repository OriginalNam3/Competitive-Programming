// Problem: C. Monsters And Spells
// Contest: Codeforces - Educational Codeforces Round 121 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1626/problem/C
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

void solve(){
	int n;
	cin >> n;
	vi k(n);
	vi h(n);
	each(x, k) cin >> x;
	each(x, h) cin >> x;
	vi dp(n);
	set<pi> seg;
	seg.insert(mp(k[0] - h[0], k[0]));
	forn(i, 1, n){
		int l = k[i] - h[i], r = k[i];
		while (!seg.empty()){
			int nl = seg.rbegin()->f, nr = seg.rbegin()->s;
			if (nr <= l){
				seg.insert(mp(l, r));
				break;
			}
			if (nl <= l){
				seg.erase(mp(nl, nr));
				seg.insert(mp(nl, r));
				break;
			}
			else{
				seg.erase(mp(nl, nr));
			}
		}
		if (seg.empty()) seg.insert(mp(l, r));
	}
	ll ans = 0;
	while(!seg.empty()){
		int l = seg.begin()->f, r = seg.begin()->s;
		// debug(l); debug(r);
		seg.erase(seg.begin());
		ans += 1LL * (r - l) * (r - l + 1) / 2;
	}
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
