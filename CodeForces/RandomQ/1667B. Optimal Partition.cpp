// Problem: B. Optimal Partition
// Contest: Codeforces - Codeforces Round #783 (Div. 1)
// URL: https://codeforces.com/contest/1667/problem/B
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Date & Time: 2022-04-26 12:02:11
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


template<class T> struct st {
	const T ID = INT_MIN;  // cmb(ID, a) = a
	T cmb (T a, T b) {return max(a, b);}  // Function for combining two nodes
	int n; vector<T> tree;
	void set(int size){  // Set segtree size
		for (n = 1; n < size;) n <<= 1;
		tree.assign(2 * n, ID);
	}
	void update(int i, T v){  // Set value at index i to v and update ancestors
		tree[n + i] = v;
		for (i = (n + i)/2; i >= 1; i /= 2) 
			tree[i] = cmb(tree[2 * i], tree[2 * i + 1]);
	}
	T query(int l, int r){  // Query for range [l, r]
		T ra = ID, rb = ID;
		for (l += n, r += n + 1; l < r; l /= 2, r /= 2){
			if (l & 1) ra = cmb(ra, tree[l++]);
			if (r & 1) rb = cmb(rb, tree[--r]);
		}
		return cmb(ra, rb);
	}
};

void solve(){
	int n;
	cin >> n;
	vi a(n);
	each(x, a) cin >> x;

	vll pref(n);
	pref[0] = a[0];
	vector<pair<ll, int> > b;
	b.pb(mp(pref[0], 0));
	forn(i, 1, n){
		pref[i] = pref[i-1] + a[i];
		b.pb(mp(pref[i], -i));
		// debug(pref[i]);
	}
	
	vi ord(n);
	sor(b);
	forn(i, 0, n){
		ord[-b[i].s] = i;
	}
	
	st<int> seg;
	seg.set(n);
	
	vi dp(n+1);
	forn(i, 1, n+1){
		if (pref[i-1] > 0){
			dp[i] = i;
		}
		else{
			dp[i] = dp[i-1] + (a[i-1] > 0 ? 1 : (a[i-1] < 0 ? -1 : 0));
			dp[i] = max(dp[i], seg.query(0, ord[i-1]) + i);
		}
		seg.update(ord[i-1], dp[i] - i);
		// debug(ord[i-1]); debug(dp[i] - i); debug(dp[i]);
	}
	
	cout << dp[n] << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
