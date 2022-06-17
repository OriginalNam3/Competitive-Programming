// Problem: F - Operations on a Matrix
// Contest: AtCoder - NOMURA Programming Contest 2022（AtCoder Beginner Contest 253）
// URL: https://atcoder.jp/contests/abc253/tasks/abc253_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-13 15:45:40
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent husbando <3

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

#define mp make_pair
#define f first
#define s second

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb emplace_back

#ifdef ORIGINAL_LOCAL
#include <bits/debug.h>
#else
#define dbg(...) 42
#endif

const int mod = 1e9+7;
int mul(int a, int b) {return (1LL * a * b) % mod;}

template<class T> struct st {
	const T ID = 0;  // cmb(ID, a) = a
	T cmb (T a, T b) {return a + b;}  // Function for combining two nodes
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
			if (r & 1) rb = cmb(tree[--r], rb);
		}
		return cmb(ra, rb);
	}
};

void solve(){
	int n, m, q;
	cin >> n >> m >> q;
	
	vector<pair<ll, int> > rows(n, pair<ll, int> (0, -1));
	vector<pair<int, pair<int, int > > > queries; 
	vector<pair<pair<int, int>, ll> > add(q);
	vector<ll> ans(q, -1);

	st<ll> seg;
	seg.set(m + 1);
	int t;
	for (int i = 0; i < q; i++){
		cin >> t;
		dbg(t, i);
		dbg(ans);
		if (t == 1){
			cin >> add[i].f.f >> add[i].f.s >> add[i].s;
			add[i].f.f--;
			seg.update(add[i].f.f, seg.query(add[i].f.f, add[i].f.f) + add[i].s);
			seg.update(add[i].f.s, seg.query(add[i].f.s, add[i].f.s) - add[i].s);
			continue;
		}
		if (t == 2){
			int r, x;
			cin >> r >> x;
			r--;
			rows[r].f = x; 
			rows[r].s = i;
			continue;
		}
		if (t == 3){
			int x, y;
			cin >> x >> y;
			
			x--; y--;
			ans[i] = seg.query(0, y) + rows[x].f;
			dbg(rows[x], seg.query(0, y));
			
			if (rows[x].s != -1) queries.pb(mp(rows[x].s, mp(i, y)));
		}
	}
	dbg(ans);
	
	seg.set(m + 1);
	int cur = 0;
	sor(queries);
	dbg(queries);
	queries.pb(mp(-1, mp(0, 0)));
	for (int i = 0; i < q; i++){
		if (ans[i] != -1) {
			cout << ans[i] << "\n";
		}
		
		seg.update(add[i].f.f, seg.query(add[i].f.f, add[i].f.f) + add[i].s);
		seg.update(add[i].f.s, seg.query(add[i].f.s, add[i].f.s) - add[i].s);
		
		while (i == queries[cur].f){
			ans[queries[cur].s.f] -= seg.query(0, queries[cur].s.s);
			dbg(cur, queries[cur]);
			cur++;
		}
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
