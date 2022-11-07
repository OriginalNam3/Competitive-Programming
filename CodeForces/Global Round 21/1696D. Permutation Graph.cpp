// Problem: D. Permutation Graph
// Contest: Codeforces - Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-25 16:59:35
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

template<class T> struct mnst {
	const T ID = INT_MAX;  // cmb(ID, a) = a
	T cmb (T a, T b) {return min(a, b);}  // Function for combining two nodes
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

template<class T> struct mxst {
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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	mxst<int> mx;
	mnst<int> mn;
	mx.set(n + 1);
	mn.set(n + 1);
	vector<int> ind(n + 1);
	for (int i = 0; i < n; i++){
		mx.tree[i + mx.n] = mn.tree[i + mn.n] = a[i];
		ind[a[i]] = i;
	}
	dbg(ind);
	mx.fullupdate();
	mn.fullupdate();
	dbg(mx.query(0, 4));
	
	dbg(a);
	int ans = 0, i = 0;
	while (i != n - 1){
		dbg(i, a[i]);
		int l = i + 1, r = n;
		while (l < r){
			int m = (l + r)/2;
			dbg(l, r);
			if (mx.query(i, m) == a[i]){
				l = m + 1;
			}
			else{
				r = m;
			}
		}
		int mxr = l - 1;
		l = i + 1, r = n;
		while (l < r){
			dbg(l, r);
			int m = (l + r)/2;
			if (mn.query(i, m) == a[i]){
				l = m + 1;
			}
			else{
				r = m;
			}
		}
		int mnr = l - 1;
		dbg(mxr, mnr);
		int mnl = mn.query(i, mxr), mxl = mx.query(i, mnr);
		i++;
		i = max(i, ind[mnl]);
		i = max(i, ind[mxl]);
		ans++;
	}
	
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while (t--)
    solve();
}
