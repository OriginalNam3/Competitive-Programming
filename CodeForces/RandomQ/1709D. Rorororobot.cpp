// Problem: D. Rorororobot
// Contest: Codeforces - Educational Codeforces Round 132 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1709/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-07-27 15:16:58
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
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

template<class T> struct st {
	const T ID = 0;  // cmb(ID, a) = a
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
	void fullupdate(){
		for (int i = n - 1; i >= 1; i--){
			tree[i] = cmb(tree[2 * i], tree[2 * i + 1]);
		}
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
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int &x: a) cin >> x;
	
	st<int> seg;
	seg.set(m);
	for (int i = 0; i < m; i++){
		seg.tree[i + seg.n] = a[i];
	}
	seg.fullupdate();
	
	int q;
	cin >> q;
	while (q--){
		int xs, ys, xf, yf, k;
		cin >> xs >> ys >> xf >> yf >> k;
		xs--, ys--, xf--, yf--;
		dbg(xs, a[ys]);
		dbg(xf >= a[yf], xs >= a[xs], abs(xf - xs) % k == 0, abs(yf - ys) % k == 0, (n - 1 - ((n - 1 - xs) % k)) >= seg.query(min(ys, yf), max(ys, yf)));
		if (xf >= a[yf] && xs >= a[ys] && abs(xf - xs) % k == 0 && abs(yf - ys) % k == 0 && (n - 1 - ((n - 1 - xs) % k)) >= seg.query(min(ys, yf), max(ys, yf))){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
}
