// Problem: C. Rooks Defenders
// Contest: Codeforces - Codeforces Round #791 (Div. 2)
// URL: https://codeforces.com/contest/1679/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-14 10:35:13
// 
// Powered by CP Editor (https://cpeditor.org)

// You either sink in the coom, or coom in the sink.

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

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    st<int> row, col, r, c;
    row.set(n+1);
    col.set(n+1);
    r.set(n+1);
    c.set(n+1);
    
    for (int i = 0; i < q; i++){
    	int t;
    	cin >> t;
    	// vdebug(row.tree) vdebug(col.tree)
    	if (t == 1){
    		int x, y;
    		cin >> x >> y;
    		row.update(x, row.query(x, x) + 1);
    		r.update(x, 1);
    		col.update(y, col.query(y, y) + 1);
    		c.update(y, 1);
    	}
    	if (t == 2){
    		int x, y;
    		cin >> x >> y;
    		row.update(x, row.query(x, x) - 1);
    		if (row.query(x, x) == 0){
    			r.update(x, 0);
    		}
    		col.update(y, col.query(y, y) - 1);
    		if (col.query(y, y) == 0){
    			c.update(y, 0);
    		}
    		
    	}
    	if (t == 3){
    		int x1, y1, x2, y2;
    		cin >> x1 >> y1 >> x2 >> y2;
    		int cnt1 = x2 - x1 + 1 - r.query(x1, x2), cnt2 = y2 - y1 + 1 - c.query(y1, y2);
    		// debug(cnt1) debug(cnt2)
    		if (cnt1 > 0 && cnt2 > 0){
    			cout << "No\n";
    		}
    		else{
    			cout << "Yes\n";
    		}
    	}
    }
}
