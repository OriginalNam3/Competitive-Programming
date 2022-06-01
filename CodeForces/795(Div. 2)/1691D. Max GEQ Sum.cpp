// Problem: D. Max GEQ Sum
// Contest: Codeforces - CodeCraft-22 and Codeforces Round #795 (Div. 2)
// URL: https://codeforces.com/contest/1691/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// Date & Time: 2022-05-31 15:35:05
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

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

template<class T> struct st {
	const T ID = LLONG_MIN;  // cmb(ID, a) = a
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
	
	st<int> mx;
	mx.set(n);
	for (int i = 0; i < n; i++){
		mx.update(i, a[i]);
	}
	
	vector<ll> b(n);
	b[0] = a[0];
	st<ll> pref;
	pref.set(n);
	pref.update(0, a[0]);
	for (int i = 1; i < n; i++){
		b[i] = b[i-1] + a[i];
		pref.update(i, b[i]);
	}
	
	b.assign(n, 0);
	b[n-1] = a[n-1];
	st<ll> suff;
	suff.set(n);
	suff.update(n-1, a[n-1]);
	for (int i = n-2; i >= 0; i--){
		b[i] = b[i+1] + a[i];
		suff.update(i, b[i]);
	}
	
	for (int i = 0; i < n; i++){
		int l = 0, r = i;
		while (l < r){
			int m = (l + r)/2;
			if (mx.query(m, i) > a[i]){
				l = m + 1;
			}
			else{
				r = m;
			}
		}
		int li = l;
		l = i, r = n;
		while (l < r){
			int m = (l + r)/2;
			if (mx.query(i, m) > a[i]){
				r = m;
			}
			else{
				l = m + 1;
			}
		}
		int ri = l - 1;
		// debug(i) debug(li) debug(ri)
		if (pref.query(i, ri) > pref.query(i, i) || suff.query(li, i) > suff.query(i, i)){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
