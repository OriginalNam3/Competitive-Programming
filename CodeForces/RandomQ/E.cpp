// Problem: E. XOR on Segment
// Contest: Codeforces - Codeforces Round #149 (Div. 2)
// URL: https://codeforces.com/problemset/problem/242/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Date & Time: 2022-07-07 20:07:49
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent husbando <3

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

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
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

template<class T> struct st {
	const T ID = vector<int> (20);  // cmb(ID, a) = a
	T cmb (T a, T b) {
		vector<int> res(20);
		for (int i = 0; i < 20; i++){
			res[i] = a[i] + b[i];
		}
		return res;
	}  // Function for combining two nodes
	int n; vector<T> tree;
	vector<int> lazy;
	void set(int size){  // Set segtree size
		for (n = 1; n < size;) n <<= 1;
		tree.assign(2 * n, ID);
		lazy.assign(2 * n, 0);
	}
	void update(int i, T v){  // Set value at index i to v and update ancestors
		tree[n + i] = v;
		for (i = (n + i)/2; i >= 1; i /= 2) 
			tree[i] = cmb(tree[2 * i], tree[2 * i + 1]);
	}
	void lazy_cmb(int i){ 
		if (lazy[i] != 0) {
			int len = n/ (1 << (__lg(i)));
			for (int x = 0; x < 20; x++) {
				if (lazy[i] & (1 << x)) tree[i][x] = len - tree[i][x]; 
			}
			if (i < n) {
				lazy[2 * i] ^= lazy[i];
				lazy[2 * i + 1] ^= lazy[i];
			}
			lazy[i] = 0;
		}
	}
	void lazy_update(int l, int r, int cl, int cr, int i, int v){  // recursive range update
		// dbg(l, r, cl, cr, i, v);
		if (l <= cl && cr <= r){
			lazy[i] ^= v;
			lazy_cmb(i);
			return;
		}
		if (r < cl || cr < l){
			return;
		}
		int m = (cl + cr)/2;
		lazy_update(l, r, cl, m, 2 * i, v);
		lazy_update(l, r, m + 1, cr, 2 * i + 1, v);
		tree[i] = cmb(tree[2 * i], tree[2 * i + 1]);
		return;
	}
	T query(int l, int r, int cl, int cr, int i){  // recursive query
		// dbg(l, r, cl, cr, i);
		lazy_cmb(i);
		if (l <= cl && cr <= r){
			return tree[i];
		}
		if (r < cl || cr < l){
			return ID;
		}
		int m = (cr - cl + 1)/2;
		T res = cmb(
		query(l, r, cl, cl + m - 1, 2 * i), 
		query(l, r, cl + m, cr, 2 * i + 1));
		// dbg(res);
		return res;
	}
};

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	st<vector<int> > seg, cnt;
	seg.set(n);
	for (int i = 0; i < n; i++){
		for (int bit = 0; bit < 20; bit++){
			if (a[i] & (1 << bit)) seg.tree[seg.n + i][bit]++;
		}
	}
	for (int i = seg.n - 1; i >= 1; i--){
		dbg(seg.tree[2 * i], seg.tree[2 * i + 1]);
		seg.tree[i] = seg.cmb(seg.tree[2 * i], seg.tree[2 * i + 1]);
	}
	
	int q;
	cin >> q;
	for (int rep = 0; rep < q; rep++){
		int t;
		cin >> t;
		if (t == 1){
			int l, r;
			cin >> l >> r;
			l--; r--;
			vector<int> res = seg.query(l, r, 0, seg.n - 1, 1);
			dbg(res);
			ll ans = 0;
			for (int i = 0; i < 20; i++){
				ans += (1LL << i) * res[i];
			}
			cout << ans << "\n";
		}
		else{
			int l, r, x;
			cin >> l >> r >> x;
			l--; r--;
			seg.lazy_update(l, r, 0, seg.n - 1, 1, x);
			dbg(seg.lazy);
		}
	}
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
}
