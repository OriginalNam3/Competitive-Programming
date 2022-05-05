// URL: https://oj.uz/problem/view/NOI20_mountains

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

void solve(){
	
}

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
    int n;
    cin >> n;
    vector<pair<ll, int > > h(n);
    forn(i, 0, n){
    	cin >> h[i].f;
    	h[i].s = i;
    }
    sor(h);
    st<int> cnt;
    cnt.set(n);
    ll ans = 0;
    forn(i, 0, n){
    	vi ers;
    	while (true){
    		ans += 1LL * cnt.query(0, h[i].s - 1) * cnt.query(h[i].s+1, n-1);
    		ers.pb(h[i].s);
    		if (i >= n - 1 || h[i].f != h[i+1].f) break;
    		i++;
    	}
    	// vdebug(ers)
    	each(i, ers) cnt.update(i, 1);
    }
    cout << ans;
}
