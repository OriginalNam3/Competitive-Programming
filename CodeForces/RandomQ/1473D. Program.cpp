// Problem: D. Program
// Contest: Codeforces - Educational Codeforces Round 102 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1473/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-04-28 19:16:19
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

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

struct node{
	int top, bot, cur;
};

node mnode(int a, int b, int c){
	node newnode;
	newnode.top = a;
	newnode.bot = b;
	newnode.cur = c;
	return newnode;
}

template<class T> struct st {
	const T ID = mnode(0, 0, 0);  // cmb(ID, a) = a
	T cmb (T a, T b) {return mnode(max(a.cur + b.top, a.top), min(a.cur + b.bot, a.bot), a.cur + b.cur);}  // Function for combining two nodes
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
	int n, m;
	cin >> n >> m;
	str s;
	cin >> s;
	st<node> seg;
	seg.set(n);
	forn(i, 0, n){
		if (s[i] == '+'){
			seg.update(i, mnode(1, 0, 1));
		}
		else{
			seg.update(i, mnode(-1, 0, -1));
		}
	}
	rep(m){
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		node ans1, ans2;
		if (l == 0){
			ans1 = seg.ID;
		}
		else{
			ans1 = seg.query(0, l-1);
		}
		if (r == n-1){
			ans2 = seg.ID;
		}
		else{
			ans2 = seg.query(r+1, n-1);
		}
		node ans = seg.cmb(ans1, ans2);
		cout << ans.top - ans.bot + 1 << "\n";
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
