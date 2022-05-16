// Problem: D. New Year Concert
// Contest: Codeforces - Codeforces Round #769 (Div. 2)
// URL: https://codeforces.com/contest/1632/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Date & Time: 2022-05-13 08:54:22
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
	T cmb (T a, T b) {return a == 0 ? b: b == 0 ? a: gcd(a, b);}  // Function for combining two nodes
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    
    vector<int> ri(n);
    st<int> seg;
    seg.set(n);
    for (int i = 0; i < n; i++){
    	seg.update(i, a[i]);
    }
    
    set<pair<int, int> > segs;
    for (int i = 0; i < n; i++){
    	int l = i, r = n-1;
    	while (l < r){
    		int m = (l + r)/ 2;
    		int g = seg.query(i, m);
    		if (g == m - i + 1){
    			l = m;
    			break;
    		}
    		if (g > m - i + 1){
    			l = m + 1;
    		}
    		else{
    			r = m - 1;
    		}
    	}
    	
    	if (seg.query(i, l) == l - i + 1) {
    		segs.insert(mp(i, l));
    	}
    }
    
    vector<int> ans(n);
    while (!segs.empty()){
    	int cur = segs.begin()->s;
    	// debug(cur)
    	segs.erase(segs.begin());
    	ans[cur]++;
    	while (!segs.empty() && segs.begin()->f <= cur && cur <= segs.begin()->s){
    		segs.erase(segs.begin());
    	}
    }
    cout << ans[0] << " ";
    for (int i = 1; i < n; i++){
    	ans[i] += ans[i-1];
    	cout << ans[i] << " ";
    }
}
