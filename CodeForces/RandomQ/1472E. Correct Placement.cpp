// Problem: E. Correct Placement
// Contest: Codeforces - Codeforces Round #693 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1472/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Date & Time: 2022-04-29 10:59:33
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

template<class T> struct st {
	int cur = -1;
	const T ID = mp(INT_MAX, -1);  // cmb(ID, a) = a
	T cmb (T a, T b) {return (a.s == cur ? b: b.s == cur ? a: a.f < b.f ? a: b);}  // Function for combining two nodes
	int n; vector<T> tree;
	void set(int size){  // Set segtree size
		for (n = 1; n < size;) n <<= 1;
		tree.assign(2 * n, ID);
	}
	void update(int i, T v){  // Set value at index i to v and update ancestors
		tree[n + i].f = v.f, tree[n+i].s = v.s;
		for (i = (n + i)/2; i >= 1; i /= 2) 
			tree[i] = cmb(tree[2 * i], tree[2 * i + 1]);
	}
	T query(int l, int r){  // Query for range [l, r]
		T ra = ID, rb = ID;
		for (l += n, r += n + 1; l < r; l /= 2, r /= 2){
			if (l & 1) ra = cmb(ra, tree[l++]);
			if (r & 1) rb = cmb(tree[--r], rb);
		}
		return cmb(ra, rb);
	}
};

void solve(){
	int n;
	cin >> n;
	vector<pair<int, pair<int, int> > > a;
	vector<pair<int, int> > b(n);
	forn(i, 0, n){
		int h, w;
		cin >> h >> w;
		a.pb(mp(h, mp(w, i)));
		a.pb(mp(w, mp(h, i)));
		b[i].f = h, b[i].s = w;
	}
	n *= 2;
	st<pair<int, int> > seg;
	seg.set(n);
	sor(a);
	map<int, int> ind;
	forn(i, 0, n){
		if (i > 0 && a[i].f != a[i-1].f) ind[a[i].f] = i-1;
		seg.update(i, a[i].s);
	}
	vi ans(n/2);
	forn(i, 0, n/2){
		if (b[i].f == a[0].f){
			ans[i] = -1;
			continue;
		}
		seg.cur = i;
		pair<int, int> q = seg.query(0, ind[b[i].f]);
		// debug(q.f); debug(q.s); debug(b[i].f);
		if (q.f < b[i].s) ans[i] = q.s + 1;
		else ans[i] = -1;
	}
	each(x, ans) cout << x << " ";
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
