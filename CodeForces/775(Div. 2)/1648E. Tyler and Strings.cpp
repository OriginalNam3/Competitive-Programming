// Problem: C. Tyler and Strings
// Contest: Codeforces - Codeforces Round #775 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/problemset/problem/1648/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-07 11:26:03
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
#define pb push_back

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 998244353;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

#define N 200005

int qpow(int a, int b, int c){  // returns a^b % c
	int res = 1;
	while (b > 0){
		if (b & 1) res = (1LL * res * a) % c;
		b >>= 1;
		a = (1LL * a * a) % c;
	}
	return res;
}

template<class T> struct st {
	const T ID = 0;  // cmb(ID, a) = a
	T cmb (T a, T b) {return add(a, b);}  // Function for combining two nodes
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

int fact[N];

void solve(){
	fact[0] = 1;
	for (int i = 1; i < N; i++){
		fact[i] = mul(fact[i-1], i);
	}
	
	int n, m;
	cin >> n >> m;
	
	vector<int> s(n), t(m);
	for (int &x: s) cin >> x;
	for (int &x: t) cin >> x;

	st<int> seg;
	int r = 1;
	seg.set(N);
	for (int i = 0; i < n; i++){
		seg.update(s[i], seg.query(s[i], s[i]) + 1);
		r = mul(r, qpow(seg.query(s[i], s[i]), mod - 2, mod));
	}
	
	int ans = 0;
	for (int i = 0; i < min(n, m); i++){
		ans = add(ans, mul(mul(fact[n - i - 1], r), seg.query(0, t[i] - 1)));
		// debug(ans) debug(mseg.query(0, N - 1)) debug(seg.query(0, t[i] - 1))
		if (seg.query(t[i], t[i]) == 0) break;
		r = mul(r, seg.query(t[i], t[i]));
		seg.update(t[i], seg.query(t[i], t[i]) - 1);
	}
	
	if (n < m && seg.query(0, N - 1) == 0) ans = add(ans, 1);
	
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
