// Problem: F - Rectangle GCD
// Contest: AtCoder - AtCoder Beginner Contest 254
// URL: https://atcoder.jp/contests/abc254/tasks/abc254_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-13 17:53:22
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

ll gcd_(ll a, ll b){
	if (a < b) swap(a, b);
	while (b != 0){
		a %= b;
		swap(a, b);
	}
	return a;
}

template<class T> struct st {
	const T ID = 0;  // cmb(ID, a) = a
	T cmb (T a, T b) {return gcd_(a, b);}  // Function for combining two nodes
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
	int n, q;
	cin >> n >> q;
	
	vector<int> a(n), b(n);
	for (int &x: a) cin >> x;
	for (int &x: b) cin >> x;
	
	st<ll> aseg, bseg;
	aseg.set(n);
	bseg.set(n);
	for (int i = 1; i < n; i++){
		aseg.tree[i + aseg.n] = abs(a[i] - a[i-1]);
		bseg.tree[i + bseg.n] = abs(b[i] - b[i-1]);
	}
	
	aseg.fullupdate();
	bseg.fullupdate();
	
	for (int i = 0; i < q; i++){
		int h1, h2, w1, w2;
		cin >> h1 >> h2 >> w1 >> w2;
		h1--; h2--; w1--; w2--;
		ll ans = a[h1] + b[w1];
		ans = gcd_(ans, aseg.query(h1 + 1, h2));
		ans = gcd_(ans, bseg.query(w1 + 1, w2));
		cout << ans << "\n";
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
