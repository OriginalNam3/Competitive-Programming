// Problem: F. Desktop Rearrangement
// Contest: Codeforces - Codeforces Round #786 (Div. 3)
// URL: https://codeforces.com/contest/1674/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Date & Time: 2022-05-02 15:35:10
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
		if (l > r) return 0;
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vb> d(n, vb(m));
    vi cnt(m+1);
    forn(i, 0, n){
    	str row;
    	cin >> row;
    	forn(j, 0, m){
    		if (row[j] == '*') {
    			d[i][j] = 1;
    			cnt[j]++;
    		}
    	}
    }
    st<int> seg;
    seg.set(m);
    forn(i, 0, m){
    	seg.update(i, cnt[i]);
    }
    // vdebug(cnt)
    rep(q){
    	int x, y;
    	cin >> x >> y;
    	x--; y--;
    	d[x][y] = !d[x][y];
    	if (d[x][y]){
    		cnt[y]++;
    	}
    	else{
    		cnt[y]--;
    	}
    	// vdebug(cnt)
    	seg.update(y, cnt[y]);
    	int l = 0, r = m-1;
    	while (l < r){
    		// debug(l) debug(r)
    		int t = (l + r) / 2;
    		int a = seg.query(0, t), b = seg.query(t + 1, m-1);
    		// debug(a) debug(b)
    		if (n * (t + 1) - a >= b){
    			r = t;
    		}
    		else{
    			l = t+1;
    		}
    	}
    	int ans = seg.query(l + 1, m - 1), empty = n * (l + 1) - seg.query(0, l) - ans;
    	// debug(empty);
    	// debug(l)
    	forn(i, n - empty, n){
    		if (d[i][l]) {
    			ans++;
    			// debug(i)
    		}

    	}
    	cout << ans << "\n";
    }
}
