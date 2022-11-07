// Problem: Pokemon Battles
// Contest: CodeChef - SEP221C
// URL: https://www.codechef.com/SEP221C/problems/PBATTLE
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-09-09 20:00:54
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
	void fullupdate(){
		for (int i = n - 1; i > 0; i--){
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
	int n;
	cin >> n;
	vector<pair<int, int> > a(n), b(n);
	for (int i = 0; i < n; i++){
		cin >> a[i].f;
		a[i].s = i;
	}
	for (int i = 0; i < n; i++){
		cin >> b[i].f;
		b[i].s = i;
	}
	sor(a);
	sor(b);
	vector<int> ind(n);
	for (int i = 0; i < n; i++) ind[b[i].s] = i;
	vector<int> ans(n);
	st<int> seg;
	seg.set(n);
	int mx = 0;
	for (int i = 0; i < n; i++){
		ans[a[i].s] = i + ind[a[i].s] - seg.query(0, ind[a[i].s]);
		mx = max(mx, ans[a[i].s]);
		seg.update(ind[a[i].s], 1);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) if (ans[i] == mx) cnt++;
	cout << cnt << "\n";
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; 
	cin >> t;
	while (t--)
	solve();
}
